s = input().replace(" ", "")
t = input().replace(" ", "")
if sorted(list(s)) == sorted(list(t)):
    print("Yes")
else:
    print("No")
