f = open("candies.in","w")
f.write("100000\n")
for i in range(100000,0,-1):
    f.write(str(i)+'\n')
f.close()

