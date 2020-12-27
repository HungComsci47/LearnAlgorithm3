# include <bits/stdc++.h>
using namespace std;
int main()
{
	long long n;
	cin>>n;
	long long a[n+1];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	long long m;
	cin>>m;
	long long b[m+1];
	for(int i=1;i<=m;i++)
	{
		cin>>b[i];
	}
	long long  i=1,j=1;// i,j la 2 con tro i cho mang 1, j cho mang 2;
	long long count=0;
	long long sum1=a[1];
	long long sum2=b[1];
	long long x,z;
	while(i<=n && j<=m)
	{
		if(sum1<sum2)
	    {
	    	i++;
	    	sum1+=a[i];
		}
	    if(sum2<sum1)
		{
			j++;
			sum2+=b[j];
		}
		 if(sum1==sum2)
		{
			count++;
			i++;
			j++;
			sum1=a[i];
			sum2=b[j];
			x=i;
			z=j;
		}
	}
	if(count==0) cout<<-1;
	else if (count!=0 && (x==n+1 && z==m+1))cout<<count;
	else cout<<-1;
	return 0;
}
