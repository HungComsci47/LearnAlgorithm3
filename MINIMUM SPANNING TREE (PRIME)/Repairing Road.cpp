# include <bits/stdc++.h>
using namespace std;
# define ll long long int
# define fi first
# define se second
typedef pair<ll,int>ii;
vector<ii>adj[100005];
const ll INF=1e18;
ll dist[100005];
bool visited[100005];
int n,m;
int mst;
int prime()
{
	for(int i=1;i<=n;i++) visited[i]=false;
	for(int i=1;i<=n;i++) dist[i]=-INF;
	dist[1]=0;
	priority_queue<ii>pq;
	pq.push(ii(0,1));
	while(!pq.empty())
    {
    	int du=pq.top().fi;
    	int u=pq.top().se;
    	pq.pop();
    	if(visited[u]) continue;
    	visited[u]=true;
    	mst+=du;
    	for(int i=0;i<adj[u].size();i++)
    	{
    		int v=adj[u][i].fi;
    		int uv=adj[u][i].se;
    		if(!visited[v] && dist[v]<uv)
    		{
    			dist[v]=uv;
    			pq.push(ii(uv,v));
			}
		}
	}
	return mst;
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int testcases;
	cin>>testcases;
	for(int k=1;k<=testcases;k++)
	{
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int a,b,w;
		cin>>a>>b>>w;
		adj[a].push_back(ii(b,w));
		adj[b].push_back(ii(a,w));
	}
	mst=0;
	int res=prime();
	cout<<"Case #"<<k<<": "<<n-1<<" "<<mst;
	for(int i=1;i<=n;i++) adj[i].clear();
    }
	return 0;
}
