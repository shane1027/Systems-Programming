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



