/*HungVoCs47*/
/*
INPUT
7 11
0 1 7
0 3 5
1 2 8
1 3 9
1 4 7
2 4 5
3 4 15
3 5 6
4 5 8
4 6 9
5 6 11
OUTPUT
39
*/
# include <bits/stdc++.h>
using namespace std;
const int INF=1e9;
typedef pair<int,int>ii;
vector<ii>adj[100005];
int dist[100005];
int n,m;
vector<bool>visited(n);
bool Prime()
{
	priority_queue<ii,vector<ii>,greater<ii> >pq;
	for(int i=1;i<=n;i++) visited[i]=false;
	for(int i=1;i<=n;i++) dist[i]=INF;
	dist[0]=0;
	pq.push(ii(0,0));
	int count=0;
	while(!pq.empty())
	{
	   int u=pq.top().second;
	   int du=pq.top().first;
	   pq.pop();
	   if(visited[u]) continue;
	   visited[u]=true;
	   for(int i=0;i<adj[u].size();i++)
	   {
	     int v=adj[u][i].first;
	     int uw=adj[u][i].second;
	     if(!visited[v] && dist[v]>uw){
	     	dist[v]=uw;
	     	pq.push(ii(uw,v));
		 }
	   }
	}
	return count==n;
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int a,b,w;
		cin>>a>>b>>w;
		adj[a].push_back(ii(b,w));
		adj[b].push_back(ii(a,w));
	}
    Prime();
    if(!Prime) cout<<"Graph is not connect\n";
    else 
    {
    	int mst=0;
    	for(int i=0;i<n;i++)
    	{
    		mst+=dist[i];
		}
		cout<<mst;
	}
	return 0;
}
