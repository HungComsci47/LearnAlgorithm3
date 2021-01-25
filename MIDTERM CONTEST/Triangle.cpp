#include <bits/stdc++.h>
using namespace std;
# define ll long long int
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll n;
	cin>>n;
	long long a[n+1];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	ll dem_so_tam_giac=0;
	for(int i=0;i<n;i++)
	{
    ll k=i+1;
		for(int j=i+1;j<n;j++)
		{
			ll t=a[j]+a[i];
		    while(k<j || (k+1<n && a[i]+a[j]>a[k+1])) k++;
		    dem_so_tam_giac+=k-j;
		}
	}
	int dem_so_tam_giac_vuong=0;
	for(int i=0;i<n;i++)
	{
		ll r=i+1;
		ll l=r;
		for(int j=i+1;j<n;j++)
		{
			if(pow(a[i],2)+pow(a[j],2)>pow(a[l],2))
            {
			while(r<n && pow(a[i],2)+pow(a[j],2)>pow(a[r],2)) 
			{
				r++;
			}
			l=r;
			while(r<n && a[l]==a[r]) r++;
            }
			if(pow(a[i],2)+pow(a[j],2)==pow(a[l],2))
			{
			if(r>l) dem_so_tam_giac_vuong+=r-l;
			}
		}
	}
	ll dem_so_tam_giac_can=0;
	ll l=0;
	while(l<n)
	{
		ll numE;
		ll canchoose;
		ll numk;
		ll r=l+1;
		ll k=r;
		while(a[l]==a[r] && r<n) r++;
		while(k<n && 2*a[l]>a[k])k++;
		numE=r-l;
		canchoose=((numE)*(numE-1))/2;
		numk=k-numE;
		if(k>0) dem_so_tam_giac_can+=canchoose*numk;
		l=r;
	}
	cout<<dem_so_tam_giac<<" "<<dem_so_tam_giac_can<<" "<<dem_so_tam_giac_vuong;
	return 0;
}




