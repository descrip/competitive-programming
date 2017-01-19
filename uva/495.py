fib = [0] * 5010
fib[1] = fib[2] = 1
for i in range(3, 5001):
	fib[i] = fib[i-1] + fib[i-2]
for n in open("input.txt"):
	print("The Fibonacci number for %d is %d" % (int(n), fib[int(n)]))
