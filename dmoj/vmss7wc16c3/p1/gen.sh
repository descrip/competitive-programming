#!/bin/bash
for f in *.in
do
	n="${f%.*}"
	echo $n
	time python3 p1.py < $f > "$n.out"
	cat "$n.out"
done
