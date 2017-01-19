n,m = [int(_) for _ in input().split()]
for i in range(n):
    if i % 4 == 0:
        print("#" * m)
    elif i % 4 == 1:
        print("." * (m-1) + "#")
    elif i % 4 == 2:
        print("#" * m)
    elif i % 4 == 3:
        print("#" + "." * (m-1))
