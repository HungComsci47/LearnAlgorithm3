# include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
const int INF=987654321;
typedef pair<int,int>ii;
typedef pair<ll,int>li;
vector<ii>graph[N];
vector<ii>reverse_graph[N];
ll count_S[N],count_T[N],dist_S[N]={INF},dist_T[N]={INF};
int n,m,s,t;
void dijkstra(int s, ll dist[], ll count[], vector<pair<int,int> >graph[])
{
	fill_n(dist, N, 1e18);
	priority_queue<li,vector<li>,greater<li> >pq;
	count[s]=1;
	dist[s]=0;
	pq.push(li(0,s));
	while(!pq.empty())
	{
		ll du=pq.top().first;
		ll u=pq.top().second;
		pq.pop();
		if(dist[u]!=du) continue;
	    for(int i=0;i<graph[u].size();i++)
	    {
	    	int v=graph[u][i].first;
	    	ll uv=graph[u][i].second;
	    	if(dist[v]>=uv+du)
	    	{
	    		if(dist[v]==uv+du)
	    		{
	    			count[v]=(count[v]+count[u])%INF;
				}
				else
				{
					dist[v]=uv+du;
					count[v]=count[u];
					pq.push(li(dist[v],v));
				}
			}
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>m>>s>>t;
    int a[m+5],b[m+5],w[m+5];
    for(int i=0;i<m;i++)
    {
    	cin>>a[i]>>b[i]>>w[i];
    	graph[a[i]].push_back(ii(b[i],w[i]));
    	reverse_graph[b[i]].push_back(ii(a[i],w[i]));
	}
	dijkstra(s,dist_S,count_S,graph);
	dijkstra(t,dist_T,count_T,reverse_graph);
	ll mini=dist_S[t];
	for(int i=0;i<m;i++)
	{
		int aa=a[i],bb=b[i],ww=w[i];
		if(dist_S[aa]+ww+dist_T[bb]==mini && (count_S[aa]*count_T[bb])%INF==count_S[t])
		{
			cout<<"YES\n";
		}
		else
		{
			ll weight=mini-1-dist_S[aa]-dist_T[bb];
			if(weight>0) cout<<"CAN "<<int(ww-weight)<<"\n";
			else cout<<"NO\n";
		}
	}
	return 0;
}
