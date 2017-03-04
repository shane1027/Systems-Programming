#!/bin/bash
# Grader utility for testing reading04
echo Creating student output...
touch studentOutput.txt...
echo Running gender.sh
./gender.sh >> studentOutput.txt
printf '\n' >> studentOutput.txt
echo Running ethnic.sh...
./ethnic.sh >> studentOutput.txt
if diff -w studentOutput.txt correctOutput.txt; then
    echo All tests passed!
else
    echo Tests failed!
fi
make gender.png
make ethnic.png
make reading04.pdf
