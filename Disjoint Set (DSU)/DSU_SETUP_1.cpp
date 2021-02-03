/*HungVoCs47*/
/*
INPUT:
8 11
1 3 4
1 1 3
1 2 5 
1 6 7
2 5 6 
2 4 7 
1 5 7
2 5 6
2 4 7
1 4 7
2 5 7
OUTPUT:
No
No
Yes
No
Yes*/
# include <bits/stdc++.h>
using namespace std;
const int MAX=10;
int parent[MAX];
void make_set(int n)
{
	for(int i=1;i<=n;i++)
	{
		parent[i]=i;
	}
}
int FindSet(int u)
{
    while(parent[u]!=u) u=parent[u];
    return u;
}
void Union_Set(int u, int v)
{
	int pu=FindSet(u);
	int pv=FindSet(v);
	parent[pv]=pu;
}
int main()
{
	ios_base::sync_with_stdio(0); cout.tie(0); cout.tie(0);
	int n,q;
	cin>>n>>q;
	make_set(n);
	int u,v,t;
	while(q--)
	{
		cin>>t>>u>>v;
		if(t==1)
	    {
	    	Union_Set(u,v);
		}
		else if(t==2)
		{
			int pu=FindSet(u);
			int pv=FindSet(v);
			cout<<(pu==pv ? "Yes\n" : "No\n");
		}
	}
	return 0;
}
