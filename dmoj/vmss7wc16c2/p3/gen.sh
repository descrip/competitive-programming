#!/bin/bash
for f in *.in
do
	n="${f%.*}"
	echo $f
	time ./a.out < $f > "$n.out"
	cat "$n.out"
done
