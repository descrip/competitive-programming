s = [
"GGGGG",
"G....",
"G..GG",
"G...G",
"GGGGG"
]
n = int(input())
z = [['.' for i in range(5*n)] for j in range(5*n)]
for y in range(5):
    for x in range(5):
        if s[y][x] == "G":
            for i in range(n):
                for y2 in range(n*y, n*y+n):
                    for x2 in range(n*x, n*x+n):
                        z[y2][x2] = "G"
for i in range(5*n):
    print(''.join(z[i]))
