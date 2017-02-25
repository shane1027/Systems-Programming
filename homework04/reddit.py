#!/usr/bin/env python2.7

# python script to scrape and filter reddit links from your favorite sub!


import requests
import os
import re
import sys

# Set some defaults

FIELD='title'
LIMIT=10
SUBREDDIT='linux'
USE_REGEX = False


# Usage function

def usage(status=0):
    print '''Usage: {} [ -f FIELD -s SUBREDDIT ] regex
    -f FIELD        Which field to search (default: {})
    -n LIMIT        Limit number of articles to report (default: {})
    -s SUBREDDIT    Which subreddit to search (default: {})'''.format(os.path.basename(sys.argv[0]), FIELD, LIMIT, SUBREDDIT)
    sys.exit(status)

# Parse command line options

args = sys.argv[1:]

while len(args) and args[0].startswith('-') and len(args[0]) > 1:
    arg = args.pop(0)
    # TODO: Parse command line arguments
    if arg == '-f':
        FIELD = args.pop(0)
    elif arg == '-n':
        LIMIT = int(args.pop(0))
    elif arg == '-s':
        SUBREDDIT = args.pop(0)
    elif arg == '-h':
        usage(0)
    else:
        usage(1)

if len(args) > 1:
    usage(1)
elif len(args) == 1:
    REGEX = args.pop(0)
    USE_REGEX = True

# Define the URL and header based on user input
URL = 'http://www.reddit.com/r/{}/.json'.format(SUBREDDIT)
headers  = {'user-agent': 'reddit-{}'.format(os.environ['USER'])}
# this header prevents Error 429, a bot prevention measurement, from occurring

# Function to obtain the necessary JSON data from the URL
def get_JSON(input_url, input_header):

    response = requests.get(input_url, headers=input_header)
    if response.status_code != 200:
        print 'Subreddit unavailable!'
        sys.exit(1)

    data = response.json()

    ### The commands commented out below told me that two keys exist in this
    ### JSON data structure: 'kind' and 'data'.  'kind'\'s value if of type
    ### Unicode, and 'data' is of type dict as in dictionary, so that's what we
    ### want!
    # print data.keys()
    # print type(data['data'])

    ### Now let's check out some keys and values in this dict:
    # print data['data'].keys()
    ### This gives the results: 'modhash', 'children', 'after', and 'before'

    ### Exploring 'children':
    # print type(data['data']['children'])
    ### This told me it is of the type 'list'!

    ### Exploring said list:
    # print type(data['data']['children'][0])
    ### This returned type 'dict', so it's likely that children is a list of
    ### posts on the first page of the subreddit, and each dictionary child
    ### contains keys and values which determine attributes of posts to be
    ### rendered on the screen!!

    # lets check out the keys in this post's dictionary
    # print data['data']['children'][0].keys()
    ### which returned 'kind' and 'data'... exploring data (a dictionary):
    # print data['data']['children'][0]['data'].keys()
    ### BINGO!!  These are the keys we are looking for in a post. author,
    ### score, title, all the good stuff.

    ## Let's try get the title, author, and link from one post:
    # print data['data']['children'][0]['data']['title']
    # print data['data']['children'][0]['data']['author']
    # print data['data']['children'][0]['data']['url']
    ### That's it!! That's what we needed. great.. on to the coding:

    return data

# retrieve the value from a specific key corrsponding to a regex'able field
def get_field(json, field_key, post_num):

    return json['data']['children'][post_num]['data'][field_key]


# check if a specified field is valid
def validate_field(field):

    if field in valid_fields:
        return True
    else:
        print 'Invalid Field: {}'.format(field)
        sys.exit(1)


# cycle through each child, and check if the value matching key 'field'
# provided checks out with the regular expression.  Save the children that
# match in a list.
def regex_children(json, field, regex):
    num_children = len(json['data']['children'])
    print 'num children'
    print num_children
    matching_children = []
    for this_child in range(num_children):
        match = re.findall(regex,json['data']['children'][this_child]['data'][field])
        if len(match) > 0:
            matching_children.append(this_child)

    return matching_children


# print out desired posts
def print_posts(json,head,post_list):
    if head > len(post_list):
        head = len(post_list)
    for num in range(head):
        print_this_post = post_list[num]
        print '{}.  Title: {}'.format(num+1,get_field(json,'title',num))
        print '     Author: {}'.format(get_field(json,'author',num))
        print '     Link: {}'.format(get_field(json,'url',num))
        print '     Short: {}'
        print '\n'


 #Download the JSON data
my_json = get_JSON(URL, headers)
print type(my_json)

# Generate a list of valid fields
valid_fields = my_json['data']['children'][0]['data'].keys()
validate_field(FIELD)

# Check children against regex provided, if one was provided
if USE_REGEX:
    matched_posts = regex_children(my_json,FIELD,REGEX)
    print matched_posts
else:
    matched_posts = range(len(my_json['data']['children']))
    print matched_posts

# Now print out the first LIMIT posts
print_posts(my_json,LIMIT,matched_posts)


















