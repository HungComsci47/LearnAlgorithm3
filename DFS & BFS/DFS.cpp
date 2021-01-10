# include <bits/stdc++.h>
using namespace std;
void DFS(int V);
bool ok[100005];
vector<int>ke[1005];
int main()
{
    int V,E,starting_point;
	cin>>V>>E>>starting_point;
	for(int i=0;i<E;i++)
	{
		int a,b;
		cin>>a>>b;
		ke[a].push_back(b);
		ke[b].push_back(a);
	}
	DFS(starting_point);
	return 0;
}
void DFS(int V)
{
	ok[V]=true;
	cout<<V<<" ";
	for(int i=0;i<ke[V].size();i++)
    {
		if(!ok[ke[V][i]])
		{
		   DFS(ke[V][i]);
		}
	}
}
