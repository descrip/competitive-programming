#not very elegant ):
t = int(input())
atoi = {}
for i in range(15):
    atoi[str(chr(65+i))] = str(i//3 + 2)
for i in range(15,19):
    atoi[str(chr(65+i))] = '7'
for i in range(19,22):
    atoi[str(chr(65+i))] = '8'
for i in range(22,26):
    atoi[str(chr(65+i))] = '9'
for test in range(t):
    n = list(input().replace('-',''))
    for i in range(len(n)):
        if n[i] in atoi:
            n[i] = atoi[n[i]]
    n = ''.join(n)
    print(n[:3] + '-' + n[3:6] + '-' + n[6:10])
