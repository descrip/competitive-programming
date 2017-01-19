N = int(input())
for coll in range(N):
    a = []
    ok = True
    for i in range(3):
        a.append(input())
    a.sort(reverse=True,key = lambda x : len(x))
    for i in range(3):
        for j in range(i+1,3):
            #print(a[i][:len(a[j])],a[i][len(a[i])-len(a[j]):],a[i],a[j])
            if a[i][:len(a[j])] == a[j] or a[i][len(a[i])-len(a[j]):] == a[j]:
                ok = False
                break
        else:
            continue
        break
    if ok:
        print("Yes")
    else:
        print("No")
