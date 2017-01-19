#!/bin/bash
for f in p3_*.in
do
	n="${f%.*}"
	echo $n
	time ./a.out < $f > "$n.out"
	#cat "$n.out"
done

