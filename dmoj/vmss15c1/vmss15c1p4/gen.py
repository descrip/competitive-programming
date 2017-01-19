from random import randint,shuffle
import networkx as nx

def f(a,b):
    return randint(a,b)

t = f(1,10000)
n = f(1,2000)
g = f(1,n)

graph = nx.erdos_renyi_graph(n,0.15)
m = len(graph.edges())

groceries = list(range(1,n+2))
shuffle(groceries)

print(t,n,m,g)
for i in range(g):
    print(groceries[i])
for i in graph.edges():
    print(i[0],i[1],f(1,t//10))
