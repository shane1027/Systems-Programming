#!/bin/sh

# script to bruteforce the password in my lockbox file

# hidden_dir=/afs/nd.edu/user15/pbui/pub/oracle/lockboxes/deccbd53/3cb9ab10/99047c0f/5327d96e/
# this is the directory in which the lockbox is stored

strings /afs/nd.edu/user15/pbui/pub/oracle/lockboxes/deccbd53/3cb9ab10/99047c0f/5327d96e/sryan8.lockbox > strings.txt
# return all printable strings from the file, hoping that the password is hardcoded in the binary

# remove equals signs, put one word on each line, delete blank lines, tabs, and asterisks due to issues running crack w/ those as a password char
sed 's/=//g' strings.txt > no_equals.txt
sed 's/ /\n/g' no_equals.txt > no_spaces.txt
sed 's/\t/\n/g' no_spaces.txt > no_tabs.txt
sed '/^$/d' no_tabs.txt > no_blanks.txt
sed '/\*/d' no_blanks.txt > passwords.txt

# now read each line of the final password file and use as argument for the lockbox script
cat passwords.txt | while read line; do

        echo "Current Password: $line"
        output=`cd /afs/nd.edu/user15/pbui/pub/oracle/lockboxes/deccbd53/3cb9ab10/99047c0f/5327d96e/; ./sryan8.lockbox $line`
        if [ -n "$output" ]; then
            echo "Password Found!"
            echo "> $line"
            echo
            echo "$output"
            exit 0
        fi
    done

echo "Password not found :("




# num_pass=`wc -l strings.txt | awk '{print $1}'`
# Now that we have the potential passwords in a file, count them up

# for i in $(eval echo {1..$num_pass})
#     do
#         current_pass=`grep --context=$i strings.txt`
#         echo "Attempt $i        Current Password: $current_pass"
#         output=`cd /afs/nd.edu/user15/pbui/pub/oracle/lockboxes/deccbd53/3cb9ab10/99047c0f/5327d96e/; ./sryan8.lockbox $current_pass`
#         if [ -n "$output" ]; then
#             echo "Password Found!"
#             echo "> $current_pass"
#             exit 0
#         fi
#     done







