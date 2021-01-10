 # include <bits/stdc++.h>
using namespace std;
vector<int>bfs[1005];
bool ok[1005];
void BFS(int u);
int main()
{
	int V,E,starting_point;
	cin>>V>>E>>starting_point;
	for(int i=0;i<E;i++)
	{
		int a,b;
		cin>>a>>b;
		bfs[a].push_back(b);
		bfs[b].push_back(a);
	}
	BFS(starting_point);
	cout<<endl;
	return 0;
}
void BFS(int u)
{
   	queue<int>q;
   	q.push(u);
   	while(q.size()>0)
   	{
   		int top=q.front();q.pop();
   		cout<<top<<" ";
   		ok[top]=true;
   		for(int i=0;i<bfs[top].size();i++)
   		{
   			if(!ok[bfs[top][i]])
   			{
   				ok[bfs[top][i]]=true;
   				q.push(bfs[top][i]);
   			}
   		}
   	}
}
