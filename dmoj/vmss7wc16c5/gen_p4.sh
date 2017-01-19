#!/bin/bash
for f in p4_*.in
do
	n="${f%.*}"
	echo $n
	python3 p4.py < $f > "$n.out"
	cat "$n.out"
done

