s = [
"XXXXXXXXXXXXXXXXXXXXXXXX",
"X....XX.XXXXX.XX.XX....X",
"X.XXXXX.XXXXX.XX.XX.XXXX",
"X.X..XX.XXXXX....XX...XX",
"X.XX.XX.XXXXX.XX.XX.XXXX",
"X....XX....XX.XX.XX.XXXX",
"XXXXXXXXXXXXXXXXXXXXXXXX"
]
n = int(input())
z = [['.' for i in range(24*n)] for j in range(7*n)]
for y in range(7):
    for x in range(24):
        if s[y][x] == "X":
            for i in range(n):
                for y2 in range(n*y, n*y+n):
                    for x2 in range(n*x, n*x+n):
                        z[y2][x2] = "X"
for i in range(7*n):
    print(''.join(z[i]))
