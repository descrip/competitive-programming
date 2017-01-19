#!/bin/bash
for f in *.in
do
	n="${f%.*}"
	python3 p1.py < $f > "$n.out"
done
