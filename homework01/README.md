Homework 01
===========


## Activity 1: Permissions and ACLs

#### Question 1

1. The home folder and Private folder have the same ACL:


* Normal Rights

    * nd_campus l

    * system:administrators rlidwka

    * system:authuser l

    * sryan8 rlidwka

The Public folder has the following access control list:

* Normal rights:

    * nd_campus rlk
  
    * system:administrators rlidwka
    
    * system:authuser rlidwka

    * sryan8 rlidwka

The key for the meaning of each of these letters is as follows:

The permissions for AFS enable the possessor to perform the indicated action:

a (administer)
Change the entries on the ACL.

d (delete)
Remove files and subdirectories from the directory or move them to other directories.

i (insert)
Add files or subdirectories to the directory by copying, moving or creating.

k (lock)
Set read locks or write locks on the files in the directory.

l (lookup)
List the files and subdirectories in the directory, stat the directory itself, and issue the fs listacl command to examine the directory's ACL.

r (read)
Read the contents of files in the directory; issue the ls -l command to stat the elements in the directory.

w (write)
Modify the contents of files in the directory, and issue the UNIX chmod command to change their mode bits

##### Part A

**Therefore the home and Private folders are the same, and the Public folder has additional read and lock capabilities for the nd campus group, and has read, insert, delete, write, lock, and administer permissions on top of lookup**

##### Part B

The Private directory is private because the nd\_campus only has lookup permissions and not read or lock, and the Public directory provides nd\_campus users read and lock permissions to view contents (as well as rlidwka permissions to the authuser group) 



#### Question 2

a.) The result of the command was information from touch saying that my Permission was denied.  No, I was not able to create said file.

b.) AFS likely takes precedence since using 'ls -l' in the nd.edu/ directory shows web exists with rwx privileges and yet I cannot write a file there. 



## Activity 2: File Operations

#### Timing Commands

Here I have timed (using 'time command') various commands for moving data from a local drive to a network one, renaming a directory, moving data within the network drive, and removing a directory:

| Command                          | Elapsed Time  |
|----------------------------------|---------------|
| cp                               | 19.62 seconds |
| mv                               | 0.00 seconds  |
| mv                               | 13.17 seconds |
| rm                               | 0.02 seconds  |


1. /usr/bin/time -p cp -r /usr/share/pixmaps/\* ~/images/ 
2. /usr/bin/time -p mv images/ pixmaps/ 
3. /usr/bin/time -p mkdir /tmp/sryan8-pixmaps; mv pixmaps/ /tmp/sryan8-pixmaps/ 
4. /usr/bin/time -p rm -rf /tmp/sryan8-pixmaps/

#### Question 1

Although both utilize the 'mv' command, renaming the folder is significantly faster because it is simply updating the inode data structure to reflect the correct name.  The second time 'mv' was invoked transfers files to a directory located on the local drive, which takes significantly longer since the data must be sent from its current home on the AFS drive.

#### Question 2

Removing the directory from the local drive does not entail transferring any information that the files contain... rather, it removes the inode data structure information saying the disk space in which the files reside is being used.  They still exit but will be overwritten once the hard drive space is used for another purpose.


## Activity 3: Redirection

#### Question 1

Enter the command 'bc < math.txt' to send the contents of math.txt to the interpreter.

#### Question 2

To save the output of math.txt parsed through bc:  'bc < math.txt &> output.txt'

#### Question 3

Suppress the errors by sending stderr to the bit bucket:  'bc < math.txt > output.txt 2> /dev/null'

#### Question 4

Use the following command: 'cat math.txt | bc -q', although this is less efficient because we are running the process 'cat' on top of just redirecting an output.


## Activity 4: Pipelines

#### Question 1

Command to search for users w/ a certain shell:  'less /etc/passwd | grep -e '/sbin/nologin' -c'

#### Question 2

Command to list the number of users currently logged in:  'ps -aux | awk '{print $1}' | uniq | wc -l'

#### Question 3

Command to list the 5 largest files in /etc and suppress errors:  'du /etc 2> /dev/null | sort -n | tail -n 5'

#### Question 4

Find the number of instances of bash running:  'ps aux | awk '{print $11}' | grep -ce 'bash'


## Activity 5: Processes and Signals

#### Question 1 






























