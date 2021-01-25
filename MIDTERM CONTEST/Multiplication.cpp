#include <bits/stdc++.h>
using namespace std;
# define ll long long int
long long int phan_tich_so(ll n)
{
	ll temp=n;
	ll tong_cac_chu_so=0;
	ll t;
    while(temp>=10)
    {
        t=temp/10;
    	tong_cac_chu_so+=temp-(t*10);
    	temp=temp/10;
    }
    tong_cac_chu_so+=temp;
    return tong_cac_chu_so;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	for(int m=1;m<=T;m++)
	{
		ll N;
		ll M;
		cin>>N>>M;
		ll t=phan_tich_so(N);
		while(t>=10) t=phan_tich_so(t);
		if(t==1)
		{
			int d[5]={1,2,6,6,3};
			if(M>=6) cout<<9<<"\n";
			else
			{
			for(int i=0;i<5;i++)
			{
				if(i+1==M) cout<<d[i]<<"\n";
			}
		    }
		}
		else if(t==2)
		{
			int d[4]={2,6,6,3};
			if(M>=5) cout<<9<<"\n";
			else
			{
			for(int i=0;i<4;i++)
			{
				if(i+1==M) cout<<d[i]<<"\n";
			}
		    }
		}
		else if(t==3)
		{
			int d[3]={3,3,6};
			if(M>=4) cout<<9<<"\n";
			else
			{
			for(int i=0;i<3;i++)
			{
				if(i+1==M) cout<<d[i]<<"\n";
			}
		    }
		}
		else if(t==4)
		{
			int d[5]={4,2,3,3,6};
			if(M>=6) cout<<9<<"\n";
			else
			{
			for(int i=0;i<5;i++)
			{
				if(i+1==M) cout<<d[i]<<"\n";
			}
		    }
		}
		else if(t==5)
		{
			int d[4]={5,3,3,6};
			if(M>=5) cout<<9<<"\n";
			else
			{
			for(int i=0;i<4;i++)
			{
				if(i+1==M) cout<<d[i]<<"\n";
			}
		    }
		}
		else if(t==6)
		{
			int d[3]={6,6,3};
			if(M>=4) cout<<9<<"\n";
			else
			{
			for(int i=0;i<3;i++)
			{
				if(i+1==M) cout<<d[i]<<"\n";
			}
		    }
		}
		else if(t==7)
		{
			int d[2]={7,2};
			if(M>=3) cout<<9<<"\n";
			else
			{
			for(int i=0;i<2;i++)
			{
				if(i+1==M) cout<<d[i]<<"\n";
			}
		    }
		}
		else if(t==8)
		{
			int d[1]={1};
			if(M>=2) cout<<9<<"\n";
			else
			{
			for(int i=0;i<1;i++)
			{
				if(i+1==M) cout<<d[i]<<"\n";
			}
		    }
		}
		else if(t==9) cout<<9<<"\n";
	}
	return 0;
}

