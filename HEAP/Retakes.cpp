# include <bits/stdc++.h>
using namespace std;
typedef pair<int,int>ii;
#define ll long long
const int MAX=1e9;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	priority_queue<ii>q;
	int t[n+1];
	int c[n+1];
	int luu_vet[400005];
	int min_day=MAX;
	for(int i=1;i<=n;i++)
    {
    	cin>>t[i]>>c[i];
    	min_day=min(min_day,t[i]);
	}
	int l=min_day;
	int j=1;
	while(1)
	{
		while(j<=n && t[j]<=min_day)
		{
			q.push({c[j]-t[j],j});
			j++;
		}
		if(!q.empty())
		{
			int nzx=q.top().second;
			q.pop();
			luu_vet[nzx]=min_day;
			min_day++;	
		}
		else if(j>n) break;
		else min_day=t[j];
     }
     for(int i=1;i<=n;i++)
     {
     	cout<<luu_vet[i]<<" ";
	 }
	return 0;
}
