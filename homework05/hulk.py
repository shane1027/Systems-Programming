#!/usr/bin/env python2.7

import functools
import hashlib
import itertools
import multiprocessing
import os
import string
import sys

# Constants

ALPHABET    = string.ascii_lowercase + string.digits
ARGUMENTS   = sys.argv[1:]
CORES       = 1
HASHES      = 'hashes.txt'
LENGTH      = 1
PREFIX      = ''

# Functions

def usage(exit_code=0):
    print '''Usage: {} [-a alphabet -c CORES -l LENGTH -p PATH -s HASHES]
    -a ALPHABET Alphabet to use in permutations
    -c CORES    CPU Cores to use
    -l LENGTH   Length of permutations
    -p PREFIX   Prefix for all permutations
    -s HASHES   Path of hashes file'''.format(os.path.basename(sys.argv[0]))
    sys.exit(exit_code)


def md5sum(s):
    ''' Generate MD5 digest for given string.

    >>> md5sum('abc')
    '900150983cd24fb0d6963f7d28e17f72'

    >>> md5sum('wake me up inside')
    '223a947ce000ce88e263a4357cca2b4b'
    '''
    # TODO: Implement

    hash_md5 = hashlib.md5()
    hash_md5.update(s)

    return hash_md5.hexdigest()


def permutations(length, alphabet=ALPHABET):
    ''' Yield all permutations of alphabet of specified length.

    >>> list(permutations(1, 'ab'))
    ['a', 'b']

    >>> list(permutations(2, 'ab'))
    ['aa', 'ab', 'ba', 'bb']

    >>> list(permutations(1))       # doctest: +ELLIPSIS
    ['a', 'b', ..., '9']

    >>> list(permutations(2))       # doctest: +ELLIPSIS
    ['aa', 'ab', ..., '99']
    '''
    # TODO: Implement

    if not length:
        yield str()
    else:
        for a in alphabet:
            for prod in permutations(int(length)-1, alphabet):
                perm = a+prod
                yield perm

### The following would be much easier:
#
#    l = itertools.product(alphabet, repeat=length)  # return cartesian product
#    return ["".join(list) for list in l]  # combine formatting of return


def smash(hashes, length, alphabet=ALPHABET, prefix=''):
    ''' Return all password permutations of specified length that are in hashes

    >>> smash([md5sum('ab')], 2)
    ['ab']

    >>> smash([md5sum('abc')], 2, prefix='a')
    ['abc']

    >>> smash(map(md5sum, 'abc'), 1, 'abc')
    ['a', 'b', 'c']
    '''
    # TODO: Implement
    return [prefix+passwords for passwords in (permutations(length,
        alphabet)) if md5sum(str(prefix)+str(passwords)) in hashes]



# Main Execution

if __name__ == '__main__':      # what does this mean? Something for multicore?

    # TODO: Parse command line arguments - DONE

    while len(ARGUMENTS) and ARGUMENTS[0].startswith('-') and \
        len(ARGUMENTS[0]) > 1:
        arg = ARGUMENTS.pop(0)

        if arg == '-a':
            ALPHABET = ARGUMENTS.pop(0)
        elif arg == '-c':
            CORES = int(ARGUMENTS.pop(0))
        elif arg == '-l':
            LENGTH = int(ARGUMENTS.pop(0))
        elif arg == '-p':
            PREFIX = ARGUMENTS.pop(0)
        elif arg == '-s':
            HASHES == ARGUMENTS.pop(0)
        elif arg == '-h':
            usage(0)
        else:
            usage(1)

    # start a pool of workers with process number equal to num of cores
    pool = multiprocessing.Pool(processes=CORES)

    # TODO: Load hashes set
    hash_set = set([line.strip() for line in open(HASHES)])

    # TODO: Execute smash function to get passwords

    if LENGTH > 3:
        length_crack = 3
        length_prefix = int(LENGTH) - length_crack
    else:
        length_crack = LENGTH
        length_prefix = 0

    subsmash = functools.partial(smash, hash_set, length_crack, ALPHABET)

    prefix_gen = (PREFIX+prefix for prefix in permutations(length_prefix,
        ALPHABET))

    # Note: it's ok that prefix_gen calls the generator permutations, because
    # it will exhaust it's list after being iterated by the above definition,
    # storing the needed list of prefixes ready to be served up by prefix_gen.
    # This way, we don't interfere with the concurrent operation of
    # permutations() later on once smash is finally called by pool.

    passwords = itertools.chain.from_iterable(pool.imap(subsmash, prefix_gen))

    # TODO: Print passwords

    for p in passwords:
        print p

# vim: set sts=4 sw=4 ts=8 expandtab ft=python:
