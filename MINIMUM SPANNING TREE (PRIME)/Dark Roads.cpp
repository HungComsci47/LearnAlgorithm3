# include <bits/stdc++.h>
using namespace std;
const int INF= 1e9;
typedef pair<int,int>ii;
vector<int>dist,path;
vector<bool>visited;
vector<ii>adj[200005];
int n,m;
bool Prime(int s)
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
	return count==n;
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	while(1)
	{
		int sum=0;
		cin>>n>>m;
		int id=1e9;
		int id1;
		if(n==m && n==0) break;
		for(int i=1;i<=m;i++)
		{
			int a,b,w;
			cin>>a>>b>>w;
			adj[a].push_back(ii(b,w));
			adj[b].push_back(ii(a,w));
			sum+=w;
			id=min(id,min(a,b));
			id1=max(a,b);
		}
	int res=0;
	Prime(id);
	for(int i=0;i<n;i++)
	{
		cout<<dist[i]<<" ";
	}
	if(id1==n) res+=dist[n];
	cout<<sum-res<<"\n";
	for(int i=0;i<n;i++) adj[i].clear();
	}
	return 0;
}
