c,f,s = [int(_) for _ in input().split()]
n = int(input())
for i in range(n):
    r = input().split()
    xi = int(r.pop(0))
    ci = int(r.pop(0))
    fi = int(r.pop(0))
    si = int(r.pop(0))
    name = ' '.join(r)
    if ci / xi <= c and fi / xi <= f and si / xi <= s:
        print(name)
