/*HungVoCs47*/
# include <bits/stdc++.h>
using namespace std;
const int INF=1e9;
typedef pair<int,int>ii;
vector<ii>adj[205];
int dist[205];
bool visited[205];
int n,m;
void prime(int s)
{
   int count=0;
   int mst=0;
   for(int i=1;i<=n;i++)
   {
   	dist[i]=INF;
   	visited[i]=false;
   }
   dist[s]=0;
   priority_queue<ii,vector<ii>,greater<ii> >pq;
   pq.push(ii(0,s));
   while(!pq.empty())
   {
   	   int u=pq.top().second;
   	   int du=pq.top().first;
   	   pq.pop();
   	   if(visited[u]) continue;
   	   visited[u]=true;
   	   count++;
   	   mst+=du;
   	   for(int i=0;i<adj[u].size();i++)
   	   {
   	   	  int v=adj[u][i].first;
   	   	  int uw=adj[u][i].second;
   	   	  if(!visited[v] && dist[v]>uw)
   	   	  {
   	   	  	dist[v]=uw;
   	   	  	pq.push(ii(dist[v],v));
		  }
	   }
	}
	if(count==n) cout<<mst<<"\n";
	else cout<<-1<<"\n";
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>m;
    for(int i=0;i<m;i++)
    {
    	int a,b,w;
    	cin>>a>>b>>w;
    	adj[a].push_back(ii(b,w));
    	adj[b].push_back(ii(a,w));
    	prime(1);
	}
	return 0;
}
