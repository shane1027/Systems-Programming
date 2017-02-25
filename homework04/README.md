Homework 04
===========

## Activity 1

####How you parsed command line arguments.

Used args.pop(0) depending depending on which flag was detected.  Also used
type casting via int() if I needed to save an int.

####How you managed the temporary workspace.

Setup the temp workspace with tempfile.mkdtemp() and caught the path to this
temp directory in order to use it later.  Then upon exit, ran cleanup() which
removed this directory by registering the function with atexit.

####How you extracted the portrait URLS.

Used .format on the base url for any user profile and then added in the desired
netid.  After that, requests was used to download the webpage, and re.findall
was given the correct regular expression to filter out the URL for the profile
picture.

####How you downloaded the portrait images.

Used the implementation of wget.py we discussed in class - use requests to get
the data off the internet, then save the basename of the file to save locally,
append the temporary workspace path, and use fs.write to save the content.

####How you generated the blended composite images.

Form a string to be used for the command using .format to modify the string and
add appropriate parameters, and then pass the string to the run_command
function, which uses os.system to run the command. A loop calls this function
at the correct intervals in order to create all necessary images.

####How you generated the final animation.

Created a string to be run as a command, using .format to modify with
appropriate values, and then passed that to run_command.. if we had reverse set
to true, then the loop to include all images in the final command string was
done a second time in reverse in order to create the loop effect.

####How you checked for failure of different operations and exited early.

Catch the return value of os.system to check for failure, then call
sys.exit(1), same thing for checking whether or not URLs were valid by checking
the status_code being equal to 200.




