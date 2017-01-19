w = int(input())
n = int(input())
on = []
cnt = 0
for i in range(n):
    curr = int(input())
    if sum(on) + curr <= w:
        on.append(curr)
    else:
        break
    if len(on) == 4:
        on.pop(0)
        cnt += 1
print(cnt + len(on))
