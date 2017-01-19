for (( i=$1; i<=$2; i++))
do
	python3 gen.py > "vmss15c1p5_$i.in"
	./a.out < "vmss15c1p5_$i.in" > "vmss15c1p5_$i.out"
	cat "vmss15c1p5_$i.out"
done
