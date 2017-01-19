#!/bin/bash
for f in p2_*.in
do
	n="${f%.*}"
	echo $n
	./p2 < $f > log
	diff "$n.out" log -Z
	#cat "$n.out"
done

