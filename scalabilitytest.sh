N=2
Size=1000000
for i in {1..5}
do
	echo size = $Size > scale1-${i}.txt
	{ time ./a.out $Size 1 data10e9 test ; } 2>> scale1-${i}.txt
	((Size= Size * N))
done

N=10
Size=1
for i in {1..5}
do
	echo buffersize = $Size > scale2-${i}.txt
	{ time ./a.out 10000000 $Size data10e9 test ; } 2>> scale2-${i}.txt
	((Size= Size * N))
done
