#!/bin/bash
for f in *.in
do
	n="${f%.*}"
	echo $f
	time python3 p2.py < $f > "$n.out"
done
