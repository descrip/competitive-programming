#!/bin/bash
for f in *.in
do
	n="${f%.*}"
	python3 p2.py < $f > "$n.out"
done
