/*HungVoCs47*/
# include <bits/stdc++.h>
using namespace std;
# define ll long long 
# define fi first
# define se second
const int INF=1e9;
const int MAXN=-1e3;
typedef pair<int,int>ii;
vector<int>adj[20005];
bool visited[20005];
int parent[20005];
int n;
int find_set(int u)
{
	while(parent[u]!=u) u=parent[u];
	return u;
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int testcases;
	cin>>testcases;
	for(int k=1;k<=testcases;k++)
    {
    	int query;
    	cin>>n>>query;
    	for(int i=1;i<=n;i++)
    	{
    		int a;
    		cin>>a;
    		if(a==0)
    		{
    			parent[i]=i;
    			continue;
			}
    		parent[i]=a;
		}
		 //cout<<parent[5]<<" ";
		cout<<"Case #"<<k<<":\n";
		for(int i=1;i<=query;i++)
		{
			string s;
			cin>>s;
			if(s=="Q")
			{
				int a,b;
				cin>>a>>b;
				int pa=find_set(a);
				int pb=find_set(b);
				//cout<<pa<<" "<<pb<<" ";
				if(pa==pb) cout<<"YES\n";
				else cout<<"NO\n";
			}
			if(s=="C")
			{
				int a;
				cin>>a;
				int b=parent[a];
				if(b==a) continue;
				parent[a]=a;
				//cout<<parent[a]<<" ";
			}
		}
    }
	return 0;
}
