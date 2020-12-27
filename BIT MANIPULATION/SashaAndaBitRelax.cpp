# include <bits/stdc++.h>
using namespace std;
int main()
{
	long long int n;
	cin>>n;
	long long int a[n];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	long long int res=0;
	long long int pre[n+1];
	long long int dp[2][10000000]={0};
	pre[0]=0;
	dp[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		pre[i]=a[i]^pre[i-1];
		res+=dp[i%2][pre[i]];
		dp[i%2][pre[i]]++;
	}
	cout<<res;
    return 0;
}
