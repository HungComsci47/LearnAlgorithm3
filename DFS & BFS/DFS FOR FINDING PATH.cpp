# include<bits/stdc++.h>
using namespace std;
void DFS(int V, int F);
void trace(int V, int F);
vector<int>dfs[1005];
vector<int>a;
int ok[1005];
int truoc[1005];
int main()
{
	int V,E;
	int starting_point,ending_point;
	cin>>V>>E>>starting_point>>ending_point;
	for(int i=0;i<E;i++)
	{
		int a,b;
		cin>>a>>b;
		dfs[a].push_back(b);
		dfs[b].push_back(a);
	}
	DFS(starting_point,ending_point);
	trace(ending_point,starting_point);
	return 0;
}
void DFS(int V, int F)
{
	if(ok[F])
	{
		return;
	}
	ok[V]=true;
	cout<<V<<" ";
	for(int i=0;i<dfs[V].size();i++)
	{
		if(!ok[dfs[V][i]])
		{
			truoc[dfs[V][i]]=V;
			DFS(dfs[V][i],F);
		}
	}

}
void trace(int V, int F)
{
	if(!ok[F])
	{
		cout<<-1;
		return;
	}
	while(V!=F)
	{
		a.push_back(F);
		F=truoc[F];
	}
	a.push_back(V);
	reverse(a.begin(),a.end());
	for(int i=0;i<a.size();i++)
	{
		cout<<a[i]<<" ";
	}
}
		
			
	
