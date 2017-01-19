A = int(input())
B = int(input())
N = int(input())
H = []

for i in range(N):
    H.append(int(input()))

H += [0, 990, 1010, 1970, 2030, 2940, 3060, 3930, 4060, 4970, 5030, 5990, 6010, 7000]
H.sort()

def recur(pos, last):
    #pos - current hotel
    #last - distance since last stay
    if pos == len(H):
        return 1
    elif H[pos] - H[last] > B:
        return 0
    else:
        ret = 0
        if H[pos] - H[last] >= A:
            ret += recur(pos+1, pos)
        ret += recur(pos+1, last)
        return ret

print(int(recur(0, 0)/2))
