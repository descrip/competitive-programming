sheet = []
for y in range(10):
    sheet.append(input().split(' '))

def str_tuple(s):
    return (int(s[1]) - 1,ord(s[0]) - 65)

def recur(x,y,last):
    if (x,y) in last:
        for i in last:
            sheet[y][x] = '*'
        return
    
    if sheet[y][x] == '*':
        return
    
    if isinstance(sheet[y][x],int):
        return;
    else:
        try:
            sheet[y][x] = int(sheet[y][x])
            return
        except:
            cells = sheet[y][x].split('+')
            newvalue = 0
            for i in range(len(cells)):
                nx,ny = str_tuple(cells[i])
                recur(nx,ny,last+[(x,y)])
                if sheet[ny][nx] == '*':
                    sheet[y][x] = '*'
                    return
                newvalue += sheet[ny][nx]
            sheet[y][x] = newvalue
            
for y in range(10):
    for x in range(9):
        recur(x,y,[])
        #for y in range(10):
        #    print(' '.join([str(i) for i in sheet[y]]))
        
for y in range(10):
    print(' '.join([str(i) for i in sheet[y]]))
