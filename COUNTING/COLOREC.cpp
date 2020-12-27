# include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int a[405][405];
	int c[5][5];
	int res=0;
	for(int i=1;i<=n;i++)
	{
		int x,y,color;
		cin>>x>>y>>color;
		a[x+200][y+200]=color;
	}
	for(int x1=0;x1<=400;x1++)
	{
		for(int x2=x1+1;x2<=400;x2++)
		{
			for(int c1=1;c1<=4;c1++)
			{
				for(int c2=1;c2<=4;c2++)
				{
					c[c1][c2]=0;
				}
			}
			for(int y=0;y<=400;y++)
			{
				if(a[x1][y]!=0 && a[x2][y]!=0)
				{
					c[a[x1][y]][a[x2][y]]++;
					c[a[x2][y]][a[x1][y]]++;
				}
			}
			for(int c1=1;c1<=4;c1++)
			{
				for(int c2=c1+1;c2<=4;c2++)
				{
					int c3=-1;
					int c4=-1;
					for(int i=1;i<=4;i++)
					{
						if(i!=c1 && i!=c2)
						{
							if(c3==-1) c3=i;
							else c4=i;
						}
					}
						res+=c[c1][c2]*c[c3][c4];
				}
			
			}
			
		}
	}
	cout<<res/2;
	return 0;
}
