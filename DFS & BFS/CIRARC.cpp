# include <bits/stdc++.h>
using namespace std;
# define fi first
# define se second
int n,m;
typedef pair<int,int>ii;
vector<int>adj[1005];
int cnt[1005][1005]={0};
int parent[1005];
int mark[1005];
bool exist_cycle;
int v_back;
void DFS_find_cycle(int u)
{
	mark[u]=1;
	for(int i=0;i<adj[u].size();i++)
	{
		int v=adj[u][i];
		if(cnt[u][v]==0) continue;
		if(mark[v]==2) continue;
		parent[v]=u;
		if(mark[v]==1)
		{
			exist_cycle=true;
			v_back=v;
			break;
		}
		DFS_find_cycle(v);
		if(exist_cycle) break;	
	}
	mark[u]=2;
}
bool find_cycle()
{
  fill(mark,mark+n+1,0);
  //for(int i=1;i<=n;i++) cout<<mark[i];
  exist_cycle=false;
  for(int u=1;u<=n;u++)
  {
  	if(mark[u]==0)
  	{
  	     DFS_find_cycle(u);
		 if(exist_cycle) break;	
    }
  }
  return exist_cycle;
}
vector<ii> trace_cycle()
{
	vector<ii>cycle;
	int v=v_back;
	do
	{
		int u=parent[v];
		cycle.push_back(ii(u,v));
		v=u;
	}while(v!=v_back);
	return cycle;
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int u,v;
		cin>>u>>v;
		if(cnt[u][v]==0)
		{
		adj[u].push_back(v);
	    }
		cnt[u][v]++;
	}
	if(!find_cycle())
	{
		cout<<-1<<"\n";
		return 0;
	}
	vector<ii>cycle=trace_cycle();
	vector<ii>ans;
    for(int i=0;i<cycle.size();i++)
    {
    	ii e=cycle[i];
    	//cout<<e.fi<<" "<<e.se;
    	if(cnt[e.fi][e.se]>1) continue;
    	int temp=cnt[e.fi][e.se];
    	cnt[e.fi][e.se]=0;
    	if(!find_cycle())
    	{
    		ans.push_back(e);
    	}
    	cnt[e.fi][e.se]=temp;
	}
	//cout<<ans.size();
	if(ans.size()==0)
	{
		cout<<-1<<"\n";
		return 0;
	}
	cout<<ans.size()<<"\n";
	sort(ans.begin(),ans.end());
	for(int i=0;i<ans.size();i++)
	{
		ii e=ans[i];
		cout<<e.fi<<" "<<e.se<<"\n";
	}
	return 0;
}
