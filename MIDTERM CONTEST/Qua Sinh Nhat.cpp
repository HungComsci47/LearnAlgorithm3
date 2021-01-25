 /* HungVoCs47 */
# include <bits/stdc++.h>
using namespace std;
#define ll long long int 
long long int phan_tich_so(ll n)
{
	ll temp=n;
	ll tong_cac_chu_so=0;
    while(temp>0)
    {
        temp=temp/2;
    	tong_cac_chu_so++;
    }
    return tong_cac_chu_so;
}
long long int phan_tich_so_1(ll n)// phan tich so 1;
{
	ll temp=n;
	ll tong_cac_chu_so_1=0;
    while(temp>0)
    {
    	if(temp%2==1)tong_cac_chu_so_1++;
        temp=temp/2;
    }
    return tong_cac_chu_so_1;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin>>N;
	for(int m=1;m<=N;m++)
	{
		ll L;
		ll R;
		cin>>L>>R;
		ll bit_left=phan_tich_so(L);
		ll bit_right=phan_tich_so(R);
		ll sum_right=0;
		for(int i=0;i<bit_right;i++)
		{
			sum_right+=pow(2,i);
		}
		if(L==R) cout<<L<<"\n";
		else if(sum_right==R) cout<<R<<"\n";
		else if(R<sum_right)
		{
			ll sum_bit_1=0;
			ll sum_bit_2=0;
			for(int i=0;i<bit_right-1;i++)
			{
				sum_bit_1+=pow(2,i);
			}
			if(sum_bit_1>=L && sum_bit_1<R) cout<<sum_bit_1<<"\n";
			else if(L>sum_bit_1)
			{
				ll min=1e18;
				ll max1=-1e18;
				for(int i=L;i<=R;i++)
				{
					if(phan_tich_so_1(i)>max1)
					{
						max1=phan_tich_so_1(i);
						min=i;
					}
					else if(phan_tich_so_1(i)==max1)
					{
						if(i<min) min=i;
					}
				}
				cout<<min<<"\n";
			}
		}
	}
	return 0;
}
