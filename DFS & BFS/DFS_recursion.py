MAX = 100
graph = [[] for i in range(MAX)]
visited = [False for i in range(MAX)]
path = [-1 for i in range(MAX)]



def dfs(s):
    visited[s] = True
    print(s, end=' ')
    for v in graph[s]:
        if not visited[v]:
            path[v] = s
            dfs(v)


if __name__ == '__main__':
    V, E = map(int, input().split())
    for i in range(E):
        u, v = map(int, input().split())
        graph[u].append(v)
        graph[v].append(u)
    s = 0
    dfs(s)
