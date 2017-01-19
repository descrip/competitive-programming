#!/bin/bash
for f in *.in
do
	n="${f%.*}"
	./a.out < $f > "$n.out"
done
