/*HungVoCs47*/
# include <bits/stdc++.h>
using namespace std;
const int INF= 1e9;
typedef pair<int,int>ii;
vector<int>dist,path;
vector<bool>visited;
vector<ii>adj[200005];
int n,m;
void Prime(int s)
{
	dist.assign(n+1,INF);
	path.assign(n+1,-1);
	visited.assign(n+1,false);
	priority_queue<ii,vector<ii>,greater<ii> >pq;
	pq.push(ii(0,0));
	dist[s]=0;
	int u,v,w;
	int count=0;
	while(!pq.empty())
	{
		ii temp=pq.top();
		pq.pop();
		u=temp.second;
		if(visited[u]) continue;
		visited[u]=true;
		count++;
		for(int i=0;i<adj[u].size();i++)
		{
			int v=adj[u][i].first;
			int w=adj[u][i].second;
			if(!visited[v] && dist[v]>w)
			{
				dist[v]=w;
				path[v]=u;
				pq.push(ii(w,v));
			}
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	while(1)
	{
		cin>>n>>m;
		if(n==m && n==0) break;
		for(int i=1;i<=m;i++)
		{
			int a,b,w;
			cin>>a>>b>>w;
			adj[a].push_back(ii(b,w));
			adj[b].push_back(ii(a,w));
		}
		Prime(0);
		int luu_vet=-INF;
		for(int i=0;i<n;i++)
		{
			if(dist[i]>=luu_vet) luu_vet=dist[i];
		}
		if(luu_vet==-INF || luu_vet==INF) cout<<"Impossible\n";
		else cout<<luu_vet<<"\n";
		for(int i=0;i<n;i++) adj[i].clear();
	}
	return 0;
}
