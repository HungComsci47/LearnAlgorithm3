/*
INPUT:
4
7 2 3 1
4
1 2 5
2 4 1
3 4 1
1 3 5 
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
	ll n,i,a[10005],m,a1,b,c;
	priority_queue<ll,vector<ll>,greater<ll> >pq[20005];
	cin>>n;
	for(i=0;i<n;i++)
	cin>>a[i];
	cin>>m;
	for(i=0;i<m;i++)
	{
		cin>>a1>>b>>c;
		pq[b].push(c);
	}
	ll cnt=0;
	for(i=1;i<=n;i++)
	{
		if(pq[i].size()==0)
		cnt++;
	}
	if(cnt>1)
	{
		cout<<"-1"<<endl;
	}
	else 
	{
	ll ans=0;
	for(int i=1;i<=n;i++)
	{
		if(pq[i].size()>0)
		ans+=pq[i].top();
	}
	cout<<ans<<"\n";
	}
	return 0;
}
