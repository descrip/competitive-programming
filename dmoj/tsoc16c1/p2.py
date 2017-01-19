s = input()
a = s.split('.')
if (len(a) == 1):
    a.append(input())
a[1] = a[1].lower()
print('"' + a[0] + '" - ' + a[1])
