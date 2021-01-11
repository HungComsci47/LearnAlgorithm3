# include <bits/stdc++.h>
using namespace std;
void BFS(int u, int v);
void trace(int u, int v);
vector<int>bfs[1005];
bool ok[1005];
int truy_vet[1005];
int main()
{
	int V,E;
	int starting_point,ending_point;
	cin>>V>>E;
	cin>>starting_point>>ending_point;
	for(int i=0;i<E;i++)
	{
		int a,b;
		cin>>a>>b;
		bfs[a].push_back(b);
		bfs[b].push_back(a);
	}
	BFS(starting_point,ending_point);
	trace(ending_point,starting_point);
	return 0;
}
void BFS(int u, int v)
{
	queue<int>q;
	q.push(u);
	while(q.size()>0)
	{
		int top=q.front();q.pop();
		ok[top]=true;
		if(top==v)
		{
			return;
		}
		for(int i=0;i<bfs[top].size();i++)
		{
			if(!ok[bfs[top][i]])
			{
				ok[bfs[top][i]]=true;
				q.push(bfs[top][i]);
				truy_vet[bfs[top][i]]=top;
			}
		}
	}
}
void trace(int u, int v)
{
 	      if(!ok[u])
      {
	     cout<<-1;
	  }
	  vector<int>a;
	  while(u!=v)
	  {
	  	a.push_back(u);
	  	u=truy_vet[u];
	  }
	  a.push_back(v);
	  reverse(a.begin(),a.end());
	  for(int i=0;i<a.size();i++)
	  {
	  	cout<<a[i]<<" ";
	  }
}

 	  
	  	
	
	
	
	
	
	
