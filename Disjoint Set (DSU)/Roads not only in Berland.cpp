# include <bits/stdc++.h>
using namespace std;
typedef pair<int,int>ii;
const int MAXN=1e3+5;
int n,u,v;
vector<ii>close;
int Rank[MAXN],parent[MAXN];
void makeset()
{
	for(int i=1;i<=MAXN;i++) 
	{
		parent[i]=i;
		Rank[i]=0;
	}
}
int findset(int u)
{
	if(parent[u]!=u) parent[u]=findset(parent[u]);
	return parent[u];
}
void unionset(int u, int v)
{
	int pu=findset(u);
	int pv=findset(v);
	if(pu==pv) return;
	if(Rank[pu]>Rank[pv]) parent[pv]=pu;
	else if(Rank[pu]<Rank[pv]) parent[pu]=pv;
	else
	{
		parent[pu]=pv;
		Rank[pv]++;
	}
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	makeset();
	cin>>n;
	for(int i=0;i<n-1;i++)
	{
			cin>>u>>v;
			if(findset(u)!=findset(v)) unionset(u,v);
			else close.push_back(ii(u,v));
	}
	set<int>s;
	for(int i=1;i<=n;i++)
	{
		int x=findset(i);
		s.insert(x);
		//cout<<x<<" ";
	}
	int pre=-1;
	int index=0;
	cout<<s.size()-1<<"\n";
	for(int i=0;i<=1005;i++)
	{
	     if(s.count(i))
	     {
	     	if(pre==-1) pre=i;
	        else 
	        {
	        cout<<close[index].first<<" "<<close[index].second<<" "<<pre<<" "<<i<<'\n';
            index++;
            pre=i;
			}
		 }
	}
	return 0;
}
