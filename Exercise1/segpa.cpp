# include <bits/stdc++.h>
using namespace std;
bool check(long long int limit, long long int a[], long long int N, long long int k);
int main()
{
	long long int k,n;
	cin>>n>>k;
	long long int a[n];
	long long int mid;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	long long int left=0;
	long long int right=2e18;
	while(left<=right)
	{
		 mid=(left+right)/2;
		if(check(mid,a,n,k))
		{
			right=mid-1;
		}
		else
		{
			left=mid+1;
		}
	}
	cout<<left;
	return 0;
}
bool check(long long int limit, long long int a[], long long int N, long long int k)
{
	int u=0;
	int sum=0;
	for(int i=0;i<N;i++)
	{
		sum+=a[i];
		if(sum>limit)
		{
			u++;
			sum=a[i];
		}
	}
	u++;
	if(u<=k) return true;
	else return false;
}
