# include <bits/stdc++.h>
using namespace std;
int main()
{
	int N;
	cin>>N;
    int a[N];
    int b[N];
    int c[N];
    int d[N];
    int luu_vet[1001]={0};
    for(int i=1;i<=N;i++)
    {
    	cin>>a[i]>>b[i];
	}
	for(int i=1;i<=N;i++)
	{
		c[i]=a[i];
		d[i]=b[i];
	}
    sort(c+1,c+N+1);
    sort(d+1,d+N+1);
    int so_min=min(d[1],c[1]);
    int so_max=max(d[N],c[N]);
    for(int i=1;i<=N;i++)
    {
    	if(a[i]>b[i])
    	{
    		int temp=a[i];
    		a[i]=b[i];
    		b[i]=temp;
		}
	}
    for(int i=1;i<=N;i++)
    {
    	for(int j=a[i];j<b[i];j++)
        {
        	luu_vet[j+1]++;
		}
	}
	int max=-10000000;
	int dem=0;
	for(int i=1;i<=so_max+1;i++)
	{
		if(luu_vet[i]>max)
		{
			max=luu_vet[i];
		}
	}
	for(int i=1;i<=so_max+1;i++)
	{
		if(luu_vet[i]==max)
		{
			dem++;
		}
    }
	cout<<dem;
	return 0;
}
