/*HungVoCs47*/
# include <bits/stdc++.h>
using namespace std;
# define ll long long
typedef pair<ll,ll>ii;
typedef pair<ll,ii>iii;
const int MAX=1e5+5;
ll parent[MAX];
ll Rank[MAX];
vector<iii>edges;
vector<ii>adj[MAX];
bool visited[MAX];
ll children[MAX];
ll w[MAX];
int n,m;
void makeSet(int n)
{
	for(int i=0;i<n;i++)
	{
		parent[i]=i;
		Rank[i]=1;
	}
}
int findset(int u)
{
	if(parent[u]!=u) parent[u]=findset(parent[u]);
	return parent[u];
}
bool Unionset(int u, int v)
{
	ll pu=findset(u);
	ll pv=findset(v);
	if(pu==pv) return false;
	if(Rank[pu]>Rank[pv]) parent[pv]=pu;
	else if(Rank[pu]<Rank[pv]) parent[pu]=pv;
	else{
		parent[pv]=pu;
		Rank[pu]++;
	}
	return true;
}
int kruskal()
{
	sort(edges.begin(),edges.end());
	makeSet(n);
	for(int u,v,w,i=0;i<m;i++)
	{
		u=edges[i].second.first;
		v=edges[i].second.second;
		w=edges[i].first;
		if(Unionset(u,v))
		{
			adj[u].push_back(ii(v,w));
			adj[v].push_back(ii(u,w));
		}
	}
}
int DFS(int u)
{
	visited[u]=true;
	children[u]=1;
	for(int i=0;i<adj[u].size();i++)
	{
		ll v=adj[u][i].first;
		if(!visited[v])
		{
		     DFS(v);
		     children[u]+=children[v];
		     w[v]=adj[u][i].second;
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int u,v,zx,i=0;i<m;i++)
	{
		cin>>u>>v>>zx;
		edges.push_back(make_pair(zx,make_pair(u,v)));
	}
	 kruskal();
    for(int i=1;i<=n;i++) visited[i]=false;
    DFS(1);
    ll a[5*MAX];
    for (int i=2;i<=n;i++) a[w[i]]=children[i]*(n - children[i]);
	for (int i=0;i<=2*m;i++) {
		a[i+1]+=a[i]/2;
		a[i]%=2;
	}
    int p=2*m;
	while (a[p]==0) p--;
	for (int i=p;i>=0;i--) cout<<a[i];
	return 0;
}
