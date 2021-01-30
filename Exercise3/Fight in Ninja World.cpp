/*HungVoCs47*/
# include <bits/stdc++.h>
using namespace std;
# define ll long long int
vector<int>graph[100005];
vector<int>dist(100005);
int BFS(int s)
{
	int cnt[2]={0};
	queue<int>Q;
	Q.push(s);
	dist[s]=0;
	while(!Q.empty())
	{
		int u=Q.front();
		Q.pop();
		cnt[dist[u]%2]++;
        for(int i=0;i<graph[u].size();i++)
        {
        	int v=graph[u][i];
        	if(dist[v]==-1)
        	{
        		dist[v]=dist[u]+1;
        		Q.push(v);
			}
		}
	}
	return max(cnt[0],cnt[1]);
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int testcases;
	cin>>testcases;
	for(int k=1;k<=testcases;k++)
	{
		int n;
		cin>>n;
		int mx=0;
		for(int i=0;i<n;i++)
		{
			int a,b;
			cin>>a>>b;
			graph[a].push_back(b);
			graph[b].push_back(a);
			mx=max(mx,a);
			mx=max(mx,b);
		}
		for (int i=1;i<=mx;i++) dist[i]=-1;
		int res=0;
		for(int i=1;i<=mx;i++)
		{
			if(dist[i]==-1 && !graph[i].empty())
			{
				res+=BFS(i);
			}
		}
		for(int i=1;i<=mx;i++) graph[i].clear();
		cout<<"Case "<<k<<": "<<res<<"\n";
	}
	return 0;
}
