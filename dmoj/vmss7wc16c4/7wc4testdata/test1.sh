#!/bin/bash
for f in p1_*.in
do
	n="${f%.*}"
	echo $n
	python3 p1.py < $f > log
	diff "$n.out" log -Z
	#cat "$n.out"
done

