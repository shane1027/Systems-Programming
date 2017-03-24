Reading 05
==========

#### Question 1

What is the purpose of import sys?

- This imports the 'sys' module which provides access to variables and
  functions correlated with the interpreter.  Many additional configuration
  variables and interpreter related functions are now available to the script.

Explain what for arg in sys.argv[1:]: does.

- This expression is a for loop iterated over the returned list from
  `sys.argv[1:]`.  'sys.argv' returns the command line arguments passed to the
  python script upon being called in the operating system - the reason we are
  starting a an index of 1 and going to completion is that sys.argv[0] is
  reserved for the name of the script as it was passed to the interpreter.
  Sometimes this is a full path name, other times just the script name.

Why is there a trailing , in print arg,?

- Comma separated values correspond to Tuples in Python.  This makes the
  argument an immutable value. 

  {Suppresses the trailing newline char!!!}

#### Question 2

Explain how the command line arguments are parsed by discussing how this loop
while len(args) and args[0].startswith('-') and len(args) > 1 works.

- `args` is the list of arguments passed to the function.  The while loop above
  continues as long as the length of the list is non-zero (there is an argument
  in it), the argument at the beginning of the list starts with a hyphen, and
  the length of the argument at the beginning of the list is greater than one
  (not JUST the hyphen).
  This catches the command flags passed into the script (as long as they are
  specified BEFORE a filename). The remaining are assumed to be filenames.

What are the purposes of the following code blocks:

```if len(args) == 0:
    args.append('-')```

- If the while loop broke because len(args) == 0, then the script did not
  receive any file names as inputs.  Add a hyphen to the list to indicate this.

```if path == '-':
    stream = sys.stdin
else:
    stream = open(path)```

- If the hyphen is the item called in the list, there must've been no file
  names, so user must need to process `STDIN`.  Set `STDIN` as source.

  Otherwise, use the files specified!

What does line = line.rstrip() do? Is it necessary?

- This removes the newline character at the end of each line in a file.  yes,
  this is necessary, because we are printing a file line by line, and each line
  already contains a newline char at the end, so failing to remove this would
  space out the lines further than desired.

