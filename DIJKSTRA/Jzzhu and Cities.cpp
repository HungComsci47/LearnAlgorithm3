/* HungVoCs47 */
# include <bits/stdc++.h>
using namespace std;
# define ll long long int
typedef pair<int,int>ii;
vector<ii>adj[300005];
bool visited[300005];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m,k;
	cin>>n>>m>>k;
	while(m--)
	{
		int a,b,w;
		cin>>a>>b>>w;
		adj[a].push_back(ii(w,b));
		adj[b].push_back(ii(w,a));
	}
	priority_queue<ii>q;
	while(k--)
	{
	   int a,b;
	   cin>>a>>b;
	   q.push(ii(-b,-a));
	}
	for(int i=1;i<=n;i++)
	{
		visited[i]=false;
	}
	int res=0;
    q.push(ii(0,1));
    while(!q.empty())
    {
    	int du=q.top().first;
    	int u=q.top().second;
    	q.pop();
    	if(u<0 && visited[u=-u]==true) res++;
    	if(visited[u]==true) continue;
    	visited[u]=true;
    	for(int i=0;i<adj[u].size();i++)
    	{
    		int v = adj[u][i].second;
            int uv = adj[u][i].first;
			if (!visited[v]) {
            q.push(ii(du - uv, v));
		}
	  }
   }
   cout<<res;
	return 0;
}
