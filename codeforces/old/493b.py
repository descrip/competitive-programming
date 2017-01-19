n = int(input())
a = 0
b = 0
aseq = ''
bseq = ''
l = ''
for i in range(n):
    r = input()
    t = int(r)
    if t > 0:
        a += t
        aseq += r
        l = 'a'
    elif t < 0:
        b -= t
        bseq += str(-1 * t)
        l = 'b'

#def lexic(a,b):
    
    
if a > b:
    print("first")
elif a < b:
    print("second")
elif a == b:
    if aseq > bseq:
        print("first")
    elif aseq < bseq:
        print("second")
    else:
        if l == 'a':
            print('first')
        else:
            print('second')
