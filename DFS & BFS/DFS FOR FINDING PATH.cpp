# include <bits/stdc++.h>
using namespace std;
void input_matrix(int a[][100], int n, int m);
void dfs(int a[][100], int n, int m);
void find_way(int a, int b, int n, int m, int f[][100]);
bool ok[1005];
int main()   
{
	int n,m;
	int a[100][100];
	cin>>n>>m;
	input_matrix(a,n,m);
	dfs(a,n,m);
	return 0;
}
void input_matrix(int a[][100], int n, int m)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>a[i][j];
		}
    }
}
void dfs(int a[][100], int n, int m)
{
	int dem=0;
	int max=-1000000000;
    for(int i=0;i<n;i++)
    {
    	for(int j=0;j<m;j++)
    	{
    		if(a[i][j]==1)
    		{
    		     find_way(i,j,n,m,a);
    		     dem++;
    		}
    		if(dem>max)
    		{
    			max=dem;
			}
        }
    }
    cout<<max;
}
void find_way(int a, int b, int n, int m, int f[][100])
{
    if(f[a+1][b]==0 && f[a][b+1]==0 && f[a+1][b+1]==0)
	return;
    else
	{
		f[a][b]=0;
		find_way(a+1,b,n,m,f);
		find_way(a,b+1,n,m,f);
		find_way(a+1,b+1,n,m,f);
	}
}

