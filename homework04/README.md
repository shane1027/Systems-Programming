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



## Activity 2

####How you parsed command line arguments.

Same way as blend.py - check for appropriate flags, use argv.pop(0) to capture
a flag's input, and type casting where necessary.  Also check to see if a regex
was passed.

####How you fetched the JSON data and iterated over the articles.

Fetching the json data was done with the python requests library:

```
def get_JSON(input_url, input_header):

    response = requests.get(input_url, headers=input_header)
    if response.status_code != 200:
        print 'Subreddit unavailable!'
        sys.exit(1)

    data = response.json()
```

In order to iterate over the articles, I had to thoroughly explore the data
structure, which is well documented in some of my code's comments:

```
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
    ```

Then simply run a for loop based on `len(data['data']['children'])` in order to
iterate over each post.



####How you filtered each article based on the FIELD and REGEX.

Field was fed into my function get_field() which returned a value for the key
field in a specified post, and then re.search() was used to compare this value
to the reguar expression.  If a match was found, the post number is saved in a
list called `matched_posts`, which is then given to the function
`print_posts()` in order to print matches.

####How you generated the shortened URL.

Used the requests library:

```
# Shorten the URL given
def shorten_url(link):
    params = dict(format='json', url=link)  # have to pass dictionary to .get
    response = requests.get('http://is.gd/create.php', params=params)
    short_json = response.json()
    return short_json['shorturl']
    ```

Essentially, specify we want json, and a certain url, using a dictionary to be
passed to get().  The resulting json information can be extracted which
contains the shortened url.




## This was a really cool assignment, thanks!

Also, for the Guru point, I have a blog up at [shaneryan.me/ethics-blog][blog] for
Ethics and Professional Issues.  This is created using Jekyll, and the source
can be found here to prove it:  [Ethics Blog Repo][repo]




[blog]:http://shaneryan.me/ethics-blog/
[repo]:https://github.com/shane1027/ethics-blog/






