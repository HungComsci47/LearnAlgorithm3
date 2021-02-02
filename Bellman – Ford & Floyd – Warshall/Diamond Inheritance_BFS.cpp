/*HungVoCs47*/
# include <bits/stdc++.h>
using namespace std;
int n;
vector<int>adj[105];
bool ok[105];
int visited[105]={0};
bool BFS(int a)
{
   	queue<int>q;
   	q.push(a);
   	while(q.size()>0)
   	{
   		int u=q.front();
   		q.pop();
   		ok[u]=true;
   		if(u==a) visited[u]=0;
   		else
   		visited[u]+=1;
   		for(int i=0;i<adj[u].size();i++)
   		{
   			
   			if(ok[adj[u][i]]==false)
   			{
   		    q.push(adj[u][i]);
   		    ok[adj[u][i]]=true;
   		    }
   		    else 
   		    {
   		     visited[adj[u][i]]+=1;	
			}
        }
	}
	bool check_mate=false;
    for(int i=1;i<=n;i++) 
    {
    	if(visited[i]>=2){
    		check_mate=true;
    		break;
		}
	}
	if(check_mate) return true;
    return false;
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int testcases;
	cin>>testcases;
	for(int m=1;m<=testcases;m++)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			adj[i].clear();
			int k;
		    cin>>k;
		    for(int j=1;j<=k;j++)
		    {
		    	int v;
		    	cin>>v;
		    	adj[i].push_back(v);
			}
		}
	    for(int i=1;i<=n;i++)
	    {
	      ok[i]=false;
		}
		bool done=false;
		/*for(int i=1;i<=n;i++)
		{
		   if(BFS(i))
		   {
		   	done=true;
		   	break;
		   }	
		}*/
        for(int i=1;i<=n;i++) 
        {
        	if(BFS(i))
			{
			  done=true;
			  break;
		    }
        for(int j=1;j<=n;j++) 
		{
		    visited[j]=0;
			ok[j]=false;
		}
		}
        cout<<"Case #"<<m<<": ";
	    if(done) cout<<"Yes\n";
	    else cout<<"No\n";
        for(int j=1;j<=n;j++) 
		{
		    visited[j]=0;
			ok[j]=false;
		}
	}
	return 0;
}
