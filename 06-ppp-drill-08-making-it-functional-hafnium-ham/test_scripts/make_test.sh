#!/bin/sh

make
test -f use && echo "SUCCESS"
exit 0