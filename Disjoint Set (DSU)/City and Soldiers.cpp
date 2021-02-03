# include <bits/stdc++.h>
using namespace std;
const int MAXN=100005;
int parent[MAXN];
int rank[MAXN];
void MakeSet(int n)
{
	for(int i=1;i<=n;i++)
	{
		parent[i]=i;
	}
}
int FindSet(int u)
{
	 while (u != parent[u]) {
        u = parent[u];
    }
    return u;
}
void UnionSet(int u, int v)
{
	int pu=FindSet(u);
	int pv=FindSet(v);
	if(pu!=pv) parent[pu]=pv;
}
int main()
{
	int n,q;
	int t,u,v;
	cin>>n>>q;
	MakeSet(n);
	for(int i=1;i<=q;i++)
	{
		cin>>t;
	    if(t==1){
	    cin>>u>>v;
		UnionSet(u,v);
	    }
	     if(t==2)
	    {
	    cin>>u;
	    int pu=FindSet(u);
	    parent[pu]=u;
	    parent[u]=u;
		}
	    if(t==3)
		{
		cin>>u;
		cout<<FindSet(u)<<"\n";
		}
    }
	return 0;
}
