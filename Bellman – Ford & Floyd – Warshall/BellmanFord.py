#INPUT:
#7 16
#0 1 5
#0 7 8
#0 4 9
#1 2 12
#1 3 15
#1 7 4
#2 3 3 
#2 6 11
#3 6 9 
#4 5 4 
#4 6 20
#4 7 5
#5 2 1
#5 6 13
#7 2 7
#7 5 6
#OUTPUT:
#0 11 14 1000000007 10 22 4 


INF = int(1e9+7)
MAX = 105


class Edge:
    def __init__(self, source, target, weight):
        self.source = source
        self.target = target
        self.weight = weight


dist = [INF for i in range(MAX)]
path = [-1 for _ in range(MAX)]
graph = []

def BellmanFord(s):
    dist[s] = 0
    for i in range(1, n):
        for j in range(m):
            u = graph[j].source
            v = graph[j].target
            w = graph[j].weight
            if dist[u] != INF and dist[u]+w < dist[v]:
                dist[v] = dist[u] + w
                path[v] = u
    for i in range(m):
        u = graph[i].source
        v = graph[i].target
        w = graph[i].weight
        if dist[u] != INF and dist[u]+w < dist[v] :
            return False
    return True


def PrintPath(s, t):
    if s == t:
        print(s)
    res = []
    while t != -1:
        res.append(t)
        t = path[t]
    #res.append(s)
    res.reverse()
    for i in range(len(res)):
        print(res[i], end=' ')


if __name__ == "__main__":
    n, m = map(int, input().split())
    for i in range(m):
        u, v, w = map(int, input().split())
        graph.append(Edge(u, v, w))
    s = 1
    res = BellmanFord(s)
    if not res:
        print("DNE")
    else:
        for t in range(1, n+1):
            print(dist[t], end=' ')
        #PrintPath(s, t)
