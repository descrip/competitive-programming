#!/bin/bash
for f in p3_*.in
do
	n="${f%.*}"
	echo $n
	python3 p3.py < $f > "$n.out"
	cat "$n.out"
done
