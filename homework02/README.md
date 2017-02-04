Homework 02
===========


## Activity 1

### Question 1

#### How did you check and handle having no arguments?

Included a test at the beginning of the program to check if the number of
arguments passed to the script was greater than zero.  If so, continued
normally.  If not, echo`d a message explaining the correct usage.

### Question 2

#### How did you determine which command to use for each argument?

Shell parameter expansion to get each file`s extension, then a function with a
case statement which gave the correct command depending on extension.

### Question 3

#### What was the most challenging aspect of writing this script and how did you
\\ overcome this issue?

At first only one file would successfully extract even though I set up a for()
loop for cycling through each input along with a shift command to cycle
arguments down to $1.  Eventually I figured out the brace expansion used to
specify the range over which i should iterate was not functioning correctly due
to a nuance in expansion - using "i in {1..$#}" does not work!  the brace
expansion is handled before the shell parameter expansion of the variable.  So
I resorted to using: $(eval echo {1..$#}), which worked fine.



## Activity 2

### Question 1

#### How did you display random messages to the user?

First I executed the command `cat > responses.txt << EOF` and pasted in the
available replies from the homework description, creating a file with one
response per line.  This can be used as an input in the following command,
which shuffles the order of the lines and returns the first one, then pipes
that first line into a function that calls cowsay:

```
response=`shuf responses.txt -n 1`
display "$response"

display()
{

    echo $1 | cowsay -f tux

}
```

This scheme allowed me to change cowsay parameters globally for the duration of
the program with ease.


### Question 2

#### How did you handle signals?

Using the `trap` command, when SIGHUP, SIGINT, or SIGTERM were issued to the
program, the `haggle` function was called, which displayed a special message
before exiting the program w/ an error (exit 1).

### Question 3

#### How did you read input from the user?

Using the `read` command.  read into a variable, test to see if the variable is
non-zero, and if so, we have a response and can carry on!  If not, we must
prompt the user to input a question once again.

### Question 4

#### What was the most challenging aspect of writing this script, and how did
you overcome this issue?

This one was pretty straight-forward... I had to look up the man pages for trap
and shuf, but after reading through parts of them it was smooth sailing.  I
have cowsay installed on my local machine so the path variable was not an
issue.



## Activity 3

First command: `ping xavier.h4x0r.space` to test my connection.

Second command: `nmap -p 9000-9999 -Pn xavier.h4x0r.space` to scan ports
    note: the -Pn skips host discovery

    This returned info for three ports:

    PORT        STATE   SERVICE
    9097/tcp    open    unknown
    9111/tcp    open    DragonIDSConsole
    9876/tcp    open    sd

Third command: `traceroute xavier.h4x0r.space` which gave mostly asterisks

Fourth command: `telnet xavier.h4x0r.space 9097` which was closed by foreign
host.

Fifth command: `telnet xavier.h4x0r.space 9111` which opened up a dialogue with
a sheep.  I told it my name and a random message and it closed the connection.

Sixth command: Okay, I must need some password or passphrase to please the
Oracle.  Scanning for http server things: `nmap --script=http-enum -Pn
xavier.h4x0r.space` returned:

PORT     STATE SERVICE
22/tcp   open  ssh
8888/tcp open  sun-answerbook
9111/tcp open  DragonIDSConsole
9876/tcp open  sd


Seventh command: `nmap -sV --version-intensity 5 -Pn xavier.h4x0r.space -p
9876` which returned an unrecognized service "sd?"

Eighth command: `wget -p xavier.h4x0r.space:9111 xavier.h4x0r.space:9876`
which explained how to get my passcode by finding lockbox.

Ninth command: `find | grep -i sryan8` in the ~pbui/pub/oracle/lockboxes
directory, which returned the folder in which my files are stored.

Tenth command: changed directory to where my lockbox file is stored and
executed the script `./sryan8.lockbox`, then again with a password, but it just
exited with an error.

Eleventh command: `strings sryan8.lockbox`, which gives all printable strings
hardcoded in the file.  Now `pushd ~` to write a small script "crack.sh" to try all of
those strings until one of them works as a password for running the lockbox!

12th command: After making and running the script "crack.sh", I found that the
same task can be accomplished with the following command: `strings
sryan8.lockbox | while read line; do sryan8.lockbox $line; done`, which
returned my password: 902203a938136284fedbe6f3460afcad

13th command: `curl
xavier.h4x0r.space:9876/sryan8/902203a938136284fedbe6f3460afcad` which returned
a message for me to give to Bobbit on the slack channel for this class.

14th command:  awesome, Bobbit gave me a message for the Oracle: `ZmVsbmE4PTE0ODYxNzg0MjU=`.  Now to use `telnet xavier.h4x0r.space:9111` to connect to the Oracle.


## The Oracle accepted my message!

#### What a cool assignment, thanks pbui!

The oracle said I have it in me, but am waiting for something.  then the
awesome matrix text waterfall appeared :)






















