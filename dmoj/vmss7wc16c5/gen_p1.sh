#!/bin/bash
for f in p1_*.in
do
	n="${f%.*}"
	echo $n
	python3 p1.py < $f > "$n.out"
	cat "$n.out"
done
