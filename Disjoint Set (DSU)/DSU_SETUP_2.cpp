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
# define MAXN 1005
int parent[MAXN];
int Rank[MAXN];
void MakeSet(int n)
{
	for(int i=1;i<=n;i++)
	{
		parent[i]=i;
		Rank[i]=1;
	}
}
int Find_Set(int u)
{
     if(parent[u]!=u) parent[u]=Find_Set(parent[u]);
     return parent[u];
}
void Union_Set(int u, int v)
{
	int pu=Find_Set(u);
	int pv=Find_Set(v);
	if(pu==pv) return;
	if(Rank[pu]>Rank[pv]) parent[pv]=pu;
	else if (Rank[pu]<Rank[pv]) parent[pu]=pv;
	else
	{
		parent[pv]=pu;
		Rank[pu]++;
	}
}
int main()
{
ios_base::sync_with_stdio(0); cout.tie(0); cout.tie(0);
	int n,q;
	cin>>n>>q;
	MakeSet(n);
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
			int pu=Find_Set(u);
			int pv=Find_Set(v);
			cout<<(pu==pv ? "Yes\n" : "No\n");
		}
	}
	return 0;
}
