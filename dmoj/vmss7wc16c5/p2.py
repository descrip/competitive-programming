n = int(input())
trees = []

assert(1 <= n <= 10**3)

for i in range(n):
    x, y = [int(_) for _ in input().split()]
    assert(1 <= x <= 10**8)
    assert(1 <= y <= 10**8)
    trees.append((x,y))
trees.sort()

left = [1] * n
right = left[:]
for i in range(n-2, -1, -1):
    for j in range(i+1, n):
        if trees[j][0] - trees[i][0] <= trees[i][1]:
            right[i] = max(right[i], right[j] + j-i)
        else:
            break
for i in range(1, n):
    for j in range(i-1, -1, -1):
        if trees[i][0] - trees[j][0] <= trees[i][1]:
            left[i] = max(left[i], left[j] + i-j)
        else:
            break

for i in range(len(trees)):
    print(i%10, trees[i], trees[i][0] - trees[i][1], trees[i][0] + trees[i][1], left[i], right[i])
print([i % 10 for i in range(n)])
print(left)
print(right)

def recur(l, r):
    if l > r:
        return 0
    d = right.index(max(right[l:r+1]))
    e = left.index(max(left[l:r+1]))
    return min(recur(l+right[l], r), recur(l, r-left[r])) + 1

print(recur(0, n-1))
