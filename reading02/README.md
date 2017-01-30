Reading 02
==========


### Question 1

**1.)** Running '. ./exists.sh' would work even though it isn't executable.

**2.)** 'chmod 755 exists.sh'

**3.)** './exists.sh'

**4.)** This tells the terminal to execute the script using shell program located at /bin/sh

**5.)** 'exists.sh exists!'

**6.)** This references the first argument passed into the script.

**7.)** Checks to see if the variable '$1' exists.

**8.)** The script checks to see if an argument is passed to it when called.
    In this example, the wildcard symbol is passed as an argument... since a new terminal is opened when the script is run with './exists.sh', only the exists.sh is present in the directory, and the wildcard expansion will pass the name of the script to itself.  Thus the output is 'exists.sh exists!' when passed a wildcard.



