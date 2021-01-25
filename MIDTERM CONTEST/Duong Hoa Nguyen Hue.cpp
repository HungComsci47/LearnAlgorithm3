# include <bits/stdc++.h>
using namespace std;
vector<int>ke[100005];
bool ok[100005];
int dem_so_canh=0;
int dem_so_dinh=0;
bool is_cycle=true;
int DFS(int u)
{
	ok[u]=true;
	if(ke[u].size()!=2) is_cycle=false;
	dem_so_canh+=ke[u].size();
	dem_so_dinh+=1;
	for(int i=0;i<ke[u].size();i++)
	{
		if(!ok[ke[u][i]]){
		DFS(ke[u][i]);
    }
}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)
	{
		int n,m; // n la so dinh, m la so canh
		cin>>n>>m;
		for(int i=1;i<=m;i++)
		{
			int a,b;
			cin>>a>>b;
			ke[a].push_back(b);
			ke[b].push_back(a);
		}
		for(int i=1;i<=n;i++)
		{
			ok[i]=false;
		}
		int dem_so_thanh_phan_lien_thong=0;
		int dem_so_cay=0;
		for(int i=1;i<=n;i++)
		{
			if(!ok[i])
			{
				DFS(i);
		
                if(is_cycle==true) dem_so_thanh_phan_lien_thong+=1;
				if(dem_so_canh/2==dem_so_dinh-1) dem_so_cay+=1;
			}
			dem_so_canh=0;
			dem_so_dinh=0;
			is_cycle=true;
		}
		cout<<dem_so_cay<<" "<<dem_so_thanh_phan_lien_thong<<"\n";
		for(int i=1;i<=n;i++)
		{
			ke[i].clear();
		}
	}
	return 0;
}
