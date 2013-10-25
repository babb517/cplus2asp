#!/bin/sh
# Uses sed to extract the bare grammar rules from parser.y and outputs the results to grammar.txt
/bin/sed -rn -e 's/[{].+[}]//' -e 's/[ \t]+$//' -e 's/^([a-zA-Z0-9_]+:[ \t]+[^{]*)/\1/ p' -e 's/^([ \t]+[|;][^{]*)/\1/ p' <parser.yy >grammar.txt
