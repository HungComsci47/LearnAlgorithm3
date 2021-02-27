# include <bits/stdc++.h>
using namespace std;
# define ll long long
int digit(ll n)
{
	int ans=0;
	while(n)
	{
		ans+=n%10;
		n=n/10;
	}
	return ans;
}
ll cnt(ll n)
{
	if(n<=0) return 0;
	if(n%10==9) return 10*cnt(n/10)+(n/10+1)*45;
	return cnt(n-1)+digit(n);
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		ll a,b;
		cin>>a>>b;
		ll ans=cnt(b)-cnt(a-1);
		cout<<ans<<"\n";
	}
	return 0;
}
