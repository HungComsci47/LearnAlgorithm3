# include <bits/stdc++.h>
using namespace std;
int main()
{
	int T;
	cin>>T;
	for(int i=1;i<=T;i++)
	{
	long long int N;
	cin>>N;
	long long int a[N];// 2 M phia sau la phan tu am
	long long int luu_vet_duong[1000001]={0};
	long long int luu_vet_am[1000001]={0};
	for(int i=1;i<=N;i++)
	{
		cin>>a[i];
	}
    for(int i=1;i<=N;i++)
    {
        if(a[i]>=0)
        {
        	luu_vet_duong[a[i]]++;
		}
		else if(a[i]<0)
		{
			luu_vet_am[abs(a[i])]++;
		}
	}
	long long int sum=0;
    for(int i=0;i<=1000000;i++)
    {
    	sum+=(luu_vet_duong[i]*(luu_vet_duong[i]+1))/2;
	}
	 for(int i=1;i<=1000000;i++)
    {
    	sum+=(luu_vet_am[i]*(luu_vet_am[i]+1))/2;
	}
	cout<<sum;
	cout<<endl;
    }
	return 0;
}
