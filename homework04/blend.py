#!/usr/bin/env python2.7

import atexit
import os
import re
import shutil
import sys
import tempfile

import requests

# Global variables

REVERSE     = False
DELAY       = 20
STEPSIZE    = 5

# Functions

def usage(status=0):
    print '''Usage: {} [ -r -d DELAY -s STEPSIZE ] netid1 netid2 target
    -r          Blend forward and backward
    -d DELAY    GIF delay between frames (default: {})
    -s STEPSIZE Blending percentage increment (default: {})'''.format(
        os.path.basename(sys.argv[0]), DELAY, STEPSIZE
    )
    sys.exit(status)

# Parse command line options

args = sys.argv[1:]

while len(args) and args[0].startswith('-') and len(args[0]) > 1:
    arg = args.pop(0)
    # TODO: Parse command line arguments
    if arg == '-r':
        REVERSE = True
    elif arg == '-d':
        DELAY = int(args.pop(0))
    elif arg == '-s':
        STEPSIZE = int(args.pop(0))
    elif arg == '-h':
        usage(0)
    else:
        usage(1)

if len(args) != 3:
    usage(1)

netid = []
images = []
URL = []
PROFILE = []
netid.append(args[0])
netid.append(args[1])
target = args[2]


# Main execution

# TODO: Create workspace

TEMP_PATH = tempfile.mkdtemp()
print TEMP_PATH

# TODO: Register cleanup
def cleanup():
    print 'Cleaning up workspace: {}'.format(TEMP_PATH)
    shutil.rmtree(TEMP_PATH)

atexit.register(cleanup)

# TODO: Extract portrait URLs

# Note: use double curly braces to literally print curly braces in a .format
# string type thing {{ }}

# Also, the double quotes pass contents literally, so use single quotes,
# escaped, to double them up in the following command:

def get_URL():
    for i in range(2):
        netid_current = netid[i]

        COMMAND = 'curl -s https://engineering.nd.edu/profiles/{} | grep -oE \'(https://engineering.nd.edu/profiles/{}/@@images/[a-zA-Z0-9]{{8}}-[a-zA-Z0-9]{{4}}-[a-zA-Z0-9]{{4}}-[a-zA-Z0-9]{{4}}-[a-zA-Z0-9]{{12}}.jpeg)\' > tmp'.format(netid_current,netid_current)

        if os.system(COMMAND) == 0:
            tmp = open('tmp', 'r').readline()
            URL.append(tmp.rstrip())            # get rid of pesky \n
        else:
            print 'User profile picture not found :('
            sys.exit(1)


def get_URL_py():
    for i in range(2):
        URL = 'https://engineering.nd.edu/profiles/{}'.format(netid[i])
        print 'Searching portrait for {}...'.format(netid[i])
        REGEX = "https://engineering.nd.edu/profiles/{}/@@images/[a-zA-Z0-9]{{8}}-[a-zA-Z0-9]{{4}}-[a-zA-Z0-9]{{4}}-[a-zA-Z0-9]{{4}}-[a-zA-Z0-9]{{12}}.jpeg".format(netid[i])
        r = requests.get(URL)
        if r.status_code != 200:
            print 'Not Found!'
            sys.exit(1)
        string = r.text
        prof = re.findall(REGEX,string)
        PROFILE.append(prof[0])
        current = len(PROFILE)
        print PROFILE[current-1]




# TODO: Download portraits

def download_portrait(i):
    r = requests.get(PROFILE[i])
    n = os.path.basename(PROFILE[i])
    pathname = TEMP_PATH + '/' + n
    with open(pathname, 'wb') as fs:
        fs.write(r.content)
        print 'Downloading {} to {}...'.format(PROFILE[i],pathname)

    return pathname

# TODO: Generate blended composite images

def gen_blend(step_size):

    if step_size == 100:
        output_blend = TEMP_PATH + '/' + '100-{}_{}.gif'.format(netid[0],netid[1])
    elif step_size == 0:
        output_blend = TEMP_PATH + '/' + '000-{}_{}.gif'.format(netid[0],netid[1])
    else:
        output_blend = TEMP_PATH + '/' + '0{}-{}_{}.gif'.format(step_size,netid[0],netid[1])

    BLEND_COMMAND = 'composite -blend {} {} {} {}'.format(step_size,pic_1,pic_2,output_blend)

    run_command(BLEND_COMMAND)
    print 'Generating {} ... '.format(output_blend)

    return output_blend


def run_command(command):
    if os.system(command) != 0:
        print 'Command {} failed!'.format(command)
        sys.exit(1)
    else:
        print 'Success!'

# TODO: Generate final animation

def make_gif(input_files):

    GIF_COMMAND = 'convert -loop 0 -delay {}'.format(DELAY)
    for string in range(len(input_files)):
        GIF_COMMAND = GIF_COMMAND + ' ' + input_files[string]
    if REVERSE == True:
        for string in range(len(input_files)-1,-1,-1):
            GIF_COMMAND = GIF_COMMAND + ' ' + input_files[string]

    GIF_COMMAND = GIF_COMMAND + ' {}/{}'.format(TEMP_PATH,target)

    print 'Generating {}/{} ... '.format(TEMP_PATH,target)
    run_command(GIF_COMMAND)


## MAIN PROGRAM

get_URL_py()
pic_1 = download_portrait(0)
pic_2 = download_portrait(1)
for num in range(0,101,STEPSIZE):
    images.append(gen_blend(num))

make_gif(images)



