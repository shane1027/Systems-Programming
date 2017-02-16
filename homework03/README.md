Homework 03
===========

#### Activity 1: Caesar Cipher

How you parsed the command line arguments:

    Test to see if the first input `$1` was equal to `-h`.

How you constructed the source set (ie. SET1).

    The source set was just the input on stdin.

How you constructed the target set (ie. SET2).

    Used echo along with the brace expansion {a..z} and {A..Z}, then selected
    the appropriate point to divide the sets respectively, and flipped the
    order to construct the cipher set to be mapped upon using `tr`.

How you used both of these sets to perform the encryption.

    Using tr simply map set one onto set two, for both capital and lowercase.

#### Activity 2: Broification

How you parsed the command line arguments?

    Use a while loop to check the arguments against expected input flags.  If a
    flag is detected, capture the following argument as the corresponding
    variable and shift down twice.  Repeat until `#$ -e 0`.

How you removed comments?

    Use `sed` to match anything after $DELIM and delete the corresponding
    match.

How you removed empty lines?

    Use `sed` again, this time matching any lines that only contain \s: `s|^\s*$|d`

How the command line options affected your operations above?

    The command line options made me generalize my problem
    solving so that the command line inputs could be parsed in the desired way.

#### Activity 3: Zip Codes

How you parsed the command line arguments?

    Same way as Activity 2:  while loop that exectues until `#$ -eq 0`.  If
    there's a match for -c, -s, or -f, use the next argument as the input and
    shift down twice.  Otherwise shift down once.

How you extracted the zip codes?

    First I piped the html into less and searched for a familiar zip to see
    where it was referenced in the source.  All zips are embedded as a
    hyperlink, so I used `sed` to match every zip in context of a hyperlink on
    the page.  Capturing the matching zip and using 'p' at the end of the sed
    's' argument allowed me to print only zips, then pipe to sort and uniq to
    eliminate any possible duplicates.

How you filtered by STATE and CITY?

    Simply use a bash variable in the curl command to download the appropriate
    STATE url, and another bash variable in the sed 's' command to match the
    appropriate CITY.

How you handled the text and csv FORMAT options?

    If 'text' is desired, nothing has to be done.  For 'csv', use paste to
    concatenate multiple lines of a file (in this case STDIN) and it's flag
    `-d` to indicate a non-default delimiter (comma.)
