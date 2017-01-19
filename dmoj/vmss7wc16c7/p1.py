from random import shuffle
import string
n = int(input())
assert(1 <= n <= 500)
#l = []
for i in range(n):
    s = input()
    #l.append(s.lower())
    assert(' ' not in s and 1 <= len(s) <= 32)
    for i in s:
        assert(i in string.ascii_lowercase)
    if s[-3:] == 'one':
        print(s + " is an instrument")
    else:
        print(s + " is sadly not an instrument")
'''
shuffle(l)
for i in l:
    print(i)
'''
