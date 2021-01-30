/*HungVoCs47*/
# include <bits/stdc++.h>
using namespace std;
const int INF=1e9;
vector<vector<int> >dist;
void Floyd_Warshall(vector<vector<int> >& matrix, int n)
{
	dist.assign(n+1,vector<int>(n+1));
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(matrix[i][j]<0)
			dist[i][j]=INF;
			else
			dist[i][j]=matrix[i][j];
		}
	}
	for(int k=0;k<n;k++)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(dist[j][k]<INF && dist[i][j]>dist[i][k]+dist[k][j])
				{
					dist[i][j]=dist[i][k]+dist[k][j];
				}
			}
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int testcases;
	cin>>testcases;
	for(int _=1;_<=testcases;_++)
    {
	int n;
	cin>>n;
	vector<vector<int> >matrix(n+1,vector<int>(n+1,INF));
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
		   cin>>matrix[i][j];
	    }
	}
	Floyd_Warshall(matrix,n);
	if (dist[0][1] == 0)
         cout<<"Circuit Design #"<<_<<": Back to the drawing board\n";
      else
         cout<<"Circuit Design #"<<_<<": No more hedgehog troubles\n";
    }
	return 0;
}
