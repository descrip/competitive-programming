#!/bin/bash
for f in p2_*.in
do
	n="${f%.*}"
	echo $n
	python3 p2.py < $f > "$n.out"
	cat "$n.out"
done
