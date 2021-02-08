# include <bits/stdc++.h>
using namespace std;
typedef pair<int,int>ii;
typedef pair<int,ii>iii;
const int MAX=1e5;
int parent[MAX];
int Rank[MAX];
vector<iii>edges;
int n,m;
void makeSet(int n)
{
	for(int i=0;i<n;i++)
	{
		parent[i]=i;
		Rank[i]=1;
	}
}
int findset(int u)
{
	if(parent[u]!=u) parent[u]=findset(parent[u]);
	return parent[u];
}
bool Unionset(int u, int v)
{
	int pu=findset(u);
	int pv=findset(v);
	if(pu==pv) return false;
	if(Rank[pu]>Rank[pv]) parent[pv]=pu;
	else if(Rank[pu]<Rank[pv]) parent[pu]=pv;
	else{
		parent[pv]=pu;
		Rank[pu]++;
	}
	return true;
}
int kruskal()
{
	int mst=0;
	int cnt=0;
	sort(edges.begin(),edges.end());
	makeSet(n);
	for(int u,v,w,i=0;i<m;i++)
	{
		u=edges[i].second.first;
		v=edges[i].second.second;
		w=edges[i].first;
		if(Unionset(u,v))
		{
			cnt++;
			mst+=w;
		}
	}
	return cnt==n-1? mst:-1;
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int u,v,w,i=0;i<m;i++)
	{
		cin>>u>>v>>w;
		edges.push_back(make_pair(w,make_pair(u,v)));
	}
	int mst=kruskal();
	if(mst==-1)
	cout<<"Graph is not connect\n";
	else 
	cout<<mst<<"\n";
	return 0;
}
