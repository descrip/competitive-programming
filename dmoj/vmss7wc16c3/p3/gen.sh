#!/bin/bash
for f in *.in
do
	n="${f%.*}"
	echo $n
	time ./a.out < $f > "$n.out"
	#cat "$n.out"
done
