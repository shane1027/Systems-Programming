Homework 05
===========


## Describe how you implemented the hulk.py script. In particular, briefly discuss:

###How you generated all the candidate password combinations.

I created a generator function based on a recursive algorithm in order to
produce each cartesian product of a given length out of a given set of
characters.  This function called itself repeatedly, decrementing a value which
starts at the specified length, and begins returning combinations once the
value becomes zero.  The function returns combinations in a lexographic order
akin to turning a bike lock from 0000 --> 0001 --> 0002 ... 0010 --> 0011 and
so forth.

### How you filtered the candidates to only contain valid passwords.

Run the current generated permutation through the md5sum function, and check to
see if the generated checksum is in the set of hashes provided. If it is, we
have a cracked password!

### How you handled processing on multiple cores.

Start a pool of workers based on the desired number of processes (usually to
match the number of cores).  If a password is greater than length three, then
iterate over passwords of length three with prefixes abcd...xyz012..9.  This
allows the work of dealing with prefixed combinations to be handled in multiple
processes.  Also, all of the smash function is implemented with list
comprehension, and part is generator based.

### How you verified that your code works properly.

Attempted to crack passwords of various lengths using md5sums I generated
myself and fed into the program.  This along with the test_hulk told me
everything was in working order.



## Complete the following table for passwords of length 6:

Processes	Time

1           
2
4
8
16

##How does the number of processes utilized affect the amount of time required to crack passwords?

More processes allows the job to move more quickly.  There may be diminishing
returns or even a negative impact if the number of processes used exceeds the
number of cores a machine has by a significant amount.

## From your experience in this project and recalling your Discrete Math knowledge, what would make a password more difficult to brute-force: more complex alphabet or longer password? Explain.

Longer passwords are more difficult to brute force - I learned this from an
XKCD comic a while back. 

From a probability standpoint, if we had an alphabet of 'abc', then a three
letter password could have 3^3 = 27 possibilities.  Adding one more character 
to our alphabet ('abcd') yields 4^3 = 64 possible permutations for the same
three letter password, whereas a four character password for our original 'abc'
alphabet yields 3^4 = 81 possibilities.

    Thus, longer passwords are more difficult to crack by brute-force!!
    
    (such as horse-staple-battery-xkcd)




