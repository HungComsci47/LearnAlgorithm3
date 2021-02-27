# include <bits/stdc++.h>
using namespace std;
# define ll long long 
const ll INF=1e18;
typedef pair<ll,ll>ii;
vector<ii>adj[305];
ll dist[305];
ll n,m;
bool visited[305];
ll Prime(ll s)
{
	priority_queue<ii,vector<ii>,greater<ii> >pq;
	for(int i=1;i<=n;i++) visited[i]=false;
	for(int i=1;i<=n;i++) dist[i]=INF;
	dist[s]=0;
	pq.push(ii(0,s));
	ll mst=0;
	int cnt=0;
	while(!pq.empty())
	{
	   ll u=pq.top().second;
	   ll du=pq.top().first;
	   pq.pop();
	   if(visited[u]) continue;
	   visited[u]=true;
	   //cout<<u<<" ";
	   mst+=du;
	   cnt++;
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
	return mst;
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n;
	ll cost[305];
    ll luu_vet=1e18;
	for(int i=0;i<n;i++){
	cin>>cost[i]; 
	if(luu_vet>cost[i]) luu_vet=cost[i];
    }
	int matrix[305][305];
	for(int i=0;i<n;i++)
	  for(int j=0;j<n;j++)
	     cin>>matrix[i][j];
	for(int i=0;i<n;i++)
	  for(int j=0;j<n;j++)
	    {
	        {
	    	adj[i].push_back(ii(j,matrix[i][j]));
	    	adj[j].push_back(ii(i,matrix[j][i]));
	        }
		}
    for(int i=0;i<n;i++)
    {
    	adj[i].push_back(ii(n,cost[i]));
    	adj[n].push_back(ii(i,cost[i]));
	}
		ll sum=0;
		sum+=Prime(0);
	cout<<sum;
	return 0;
}
