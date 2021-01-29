/* HungVoCs47 */
/* 
Input:
7 16
0 1 5
0 7 8
0 4 9
1 2 12
1 3 15
1 7 4
2 3 3 
2 6 11
3 6 9 
4 5 4 
4 6 20
4 7 5
5 2 1
5 6 13
7 2 7
7 5 6
Output:
0 11 14 INF 10 22 4
*/
# include <bits/stdc++.h>
using namespace std;
const int INF=1e8;
vector<vector<int> > dist,path;
int Floyd_Warshall(vector<vector<int> >& matrix, int n)
{
   dist.assign(n+1, vector<int>(n+1));
   path.assign(n+1, vector<int>(n+1));
   for(int i=1;i<=n;i++)
   {
   	for(int j=1;j<=n;j++)
   	   {
   		dist[i][j]=i==j ? 0 : matrix[i][j];
   		if(i!=j && dist[i][j]<INF)
   		{
   			path[i][j]=i;
		}
		   else
		   path[i][j]=-1;
	   }
   }
   for(int k=1;k<=n;k++)
   {
   	for(int i=1;i<=n;i++)
   	{
   		if(dist[i][k]>=INF) continue;
   		for(int j=1;j<=n;j++)
   		{
   		   if(dist[k][j]<INF && dist[i][j]>dist[i][k]+dist[k][j])
   		   {
   		   	dist[i][j]=dist[i][k]+dist[k][j];
   		   	path[i][j]=path[k][j];
			  }
		   }
	   }
   }

   	 for(int i=1;i<=n;i++)
   	 	if(dist[i][i]<0) return false;
		return true;
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n,m;
	cin>>n>>m;
	vector<vector<int> > matrix(n+1, vector<int>(n+1,INF));
	for(int i=0;i<m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		matrix[u][v]=w;
	}
	Floyd_Warshall(matrix,n);
	for(int i=1;i<=n;i++)
	{
		cout<<dist[1][i]<<" ";
	}
	return 0;
}
