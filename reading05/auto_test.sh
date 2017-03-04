#!/bin/bash
# Author: Margaret Thomann
# Grader utility for testing reading05
echo Testing exists.py

./exists.py * && echo Success
./exists.py * ASDF || echo Success

./test_head.sh
