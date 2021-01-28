/* HungVoCs47 */
/* 
Input:
7 16
0 1 5
0 7 8
0 4 9
1 2 12
1 3 15
1 7 4
2 3 3 
2 6 11
3 6 9 
4 5 4 
4 6 20
4 7 5
5 2 1
5 6 13
7 2 7
7 5 6
Output:
0 11 14 9 10 22 4
*/
# include <bits/stdc++.h>
using namespace std;
const int INF=1e9;
struct Edge{
  	int u,v,w;
  	Edge(int u=0, int v=0, int w=0):u(u),v(v),w(w){}
};
vector<int>dist,path;
int Bellman_Ford(vector<Edge>& edges, int n, int m, int s)
{
	dist.assign(n+1,INF);
	path.assign(n+1,-1);
	dist[s]=0;
	int u,v,w;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<m;j++)
		{
			u=edges[j].u;
			v=edges[j].v;
			w=edges[j].w;
			if(dist[u]!=INF && dist[v]>dist[u]+w)
			{
				dist[v]=dist[u]+w;
				path[v]=u;
			}
		}
	}
	for(int j=0;j<m;j++)
	{
		u=edges[j].u;
		v=edges[j].v;
		w=edges[j].w;
		if(dist[u]!=INF && dist[v]>dist[u]+w)
		{
			return false;
		}
	}
	return true;
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n,m;
	cin>>n>>m;
	vector<Edge>edges;
	int u,v,w;
	for(int i=0;i<m;i++)
	{
		cin>>u>>v>>w;
		edges.push_back(Edge(u,v,w));

	}
	Bellman_Ford(edges,n,m,1);// duyet tu dinh 1;
	for(int i=1;i<=n;i++)
	{
		cout<<dist[i]<<" ";
	}
	return 0;
}
