for (( i=$1; i<=$2; i++))
do
	python2 check.py < "vmss15c1p3_$i.in"
	cat "vmss15c1p3_$i.out"
	#python3 gen.py > "vmss15c1p3_$i.in"
	#./a.out < "vmss15c1p3_$i.in" > "vmss15c1p3_$i.out"
done
