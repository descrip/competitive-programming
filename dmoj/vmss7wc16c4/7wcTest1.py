N,L = list(map(int,input().strip().split()))
def recurse(lvl,sofar):
    global L
    if (len(sofar)<=L):      
        print(sofar)
        
    if len(sofar)==L:
        return
    for i in range(lvl,N):
        for j in range(len(restrict[i])):
            recurse(i+1,sofar+restrict[i][j])
    
restrict = []
for i in range(N):
    line = input().strip().split()
    ln2= line[1:]
    ln2.sort()
    restrict.append(ln2)

for i in range(len(restrict[0])):
    
    recurse(1,restrict[0][i])
