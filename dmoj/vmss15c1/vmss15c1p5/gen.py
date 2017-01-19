from random import randint,shuffle

def f(a,b):
    return randint(a,b)

n = f(8,10)
r,s = f(700,1000),f(930,1000)

applenames = ["goldendelicious", "reddelicious", "apple", "macintosh", "gala", "fuji", "mountain", "okokokokoko", "leo", "sucks", "green", "applecomputer", "thisisaname", "asdfghjkl", "zxcvb", "laptop", "cigarette", "candy", "caramel", "icecream", "rotten", "APPL", "quack", "yokoono", "partimejob", "ermergerd", "reddit", "linux", "massey", "stang", "morris", "comsci", "sucky", "knapsack", "dp", "dynamicprogramming", "fertig", "papaoutai", "stromae", "engineer", "ccc", "www", "internet", "email", "rhode", "jemand", "panther"]
shuffle(applenames)
applenames = applenames[:n]
applenames.sort()

print(n,r,s)
for i in range(n):
    print(applenames[i],f(1,1000),f(1,30),f(1,33))
