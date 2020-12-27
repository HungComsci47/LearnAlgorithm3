# include <bits/stdc++.h>
using namespace std;
int main()
{
	long long n;
	cin>>n;
	long long a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	long long r=0;
	long long count;
	long long max=-1e9;
	for(int i=0;i<n;i++)
	{
		count=0;
		while(a[r]-a[i]<=5 && r<n)
		{
			r++;
		}
		count=(r-i);
		if(count>max)
		{
			max=count;
		}
	}
	cout<<max;
	return 0;
}
