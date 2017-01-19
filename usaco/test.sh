for testfile in $1/*.in; do
	testfilename=${testfile##*/}
	testfilename=${testfilename%.*}
	cp $testfile $1.in
	./a.out
	echo "Test "$testfile": "
	if diff -b $1.out $1/$testfilename.out > /dev/null
	then
		echo Correct
	else
		echo Incorrect
	fi
done
