/*HungVoCs47*/
# include <bits/stdc++.h>
using namespace std;
typedef pair<int,int>ii;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	while(1)
	{
                const int MAXN=1e9;
		int n,m;
		vector<ii>adj[500];
		cin>>n>>m;
		if(n==0 && m==0) break;
		string city1, city2, start;
		map<string,int>M;
		for(int i=1;i<=n;i++){
			cin>>city1;
			M[city1]=i;
		}
		for(int i=1;i<=m;i++)
		{
		  int w;
		  cin>>city1>>city2>>w;	
		  int u=M[city1];
		  int v=M[city2];
		  adj[u].push_back(ii(v,w));
		  adj[v].push_back(ii(u,w));
		}
		cin>>start;
		int id_starting_city=M[start];
		int dist[500];
		for(int i=1;i<=n;i++) dist[i]=MAXN;
		priority_queue<ii,vector<ii>,greater<ii> >pq;
		dist[id_starting_city]=0;
		pq.push(ii(0,id_starting_city));
		bool visited[500];
		for(int i=1;i<=n;i++) visited[i]=false;
		while(!pq.empty())
		{
			int du=pq.top().first;
			int u=pq.top().second;
			pq.pop();
			if(visited[u]) continue;
			visited[u]=true;
			for(int i=0;i<adj[u].size();i++)
			{
				int v=adj[u][i].first;
				int uv=adj[u][i].second;
				if(!visited[v] && dist[v]>uv)
				{
					dist[v]=uv;
				    pq.push(ii(dist[v],v));
				}
			}
		}
		int count=0;
		for(int i=1;i<=n;i++)
		{
			if(visited[i])
			{
			  count++;	
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			ans+=dist[i];
		}
		if(count!=n) cout<<"Impossible\n";
		else cout<<ans<<"\n";
	}
	return 0;
}
