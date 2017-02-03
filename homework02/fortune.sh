#!/bin/sh

# fortune.sh - ask a question and give a magic 8-ball style answer


# display function - take an input and put it out on cowsay
# useful so that if we want to change cowsay parameters, it can be a global
# style change

# the following is included so that the script functions on student machines
# in the AFS

export PATH=~pbui/pub/bin:$PATH


display()
{
    echo $1 | cowsay -f tux
}

trap haggle 1 2 15 

haggle()
{
    display "Leaving so soon?"
    exit 1
}

##############
# Main Program
##############

# display welcome message:
display "Hello $USER, what question do you have for me today?"

while [ -z "$input" ]; do
    echo -n "Question: "
    read input
    if [ -n "$input" ]; then
        response=`shuf responses.txt -n 1`
        display "$response"
    fi
done

# REFERENCE:

# Number  SIG Meaning
# 0   0   On exit from shell
# 1   SIGHUP  Clean tidyup
# 2   SIGINt  Interrupt
# 3   SIGQUIT Quit
# 6   SIGABRT Abort
# 9   SIGKILL Die Now (cannot be trap'ped)
# 14  SIGALRM Alarm Clock
# 15  SIGTERM Terminate
