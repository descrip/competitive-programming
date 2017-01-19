def rev(n):
	return int(str(n)[::-1])
n = int(input())
for i in range(n):
	a, b = [int(_) for _ in input().split()]
	print(rev(rev(a)+rev(b)))
