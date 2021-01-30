/*HungVoCs47*/
# include <bits/stdc++.h>
using namespace std;
const int INF=1e8;
vector<vector<int> >dist;
void Floyd_Warshall(vector<vector<int> >& matrix, int n)
{
	dist.assign(n+1,vector<int>(n+1));
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			dist[i][j]=i==j? 0: matrix[i][j];
		}
	}
	for(int k=0;k<n;k++)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(dist[i][k]!=INF && dist[k][j]!=INF && dist[i][j]>dist[i][k]+dist[k][j])
				{
				      dist[i][j]=dist[i][k]+dist[k][j];
				      if (dist[i][j]<-150*10000)
                      dist[i][j]=-INF;
				}
			}
		}
	}
	  for (int k=0;k<n;k++){
        for (int i=0;i<n;i++) {
            for (int j=0;j<n;j++) {
                if (dist[i][k]!=INF && dist[k][j]!=INF && dist[i][k]+dist[k][j]<dist[i][j]) {
                    dist[i][j]=-INF;
                }
            }
        }
    }
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	while(1)
	{
		int n,m,q;
		cin>>n>>m>>q;
		if(n==0) break;
		vector<vector<int> >matrix(n+1,vector<int>(n+1,INF));
		for(int i=0;i<m;i++)
		{
			int u,v,w;
			cin>>u>>v>>w;
		    matrix[u][v]=min(w,matrix[u][v]);
		}
		Floyd_Warshall(matrix,n); 
		for(int i=0;i<q;i++)
		{
			int a,b;
			cin>>a>>b;
			if (dist[a][b]==INF){
                cout << "Impossible\n";
            } else
            if (dist[a][b]==-INF) {
                cout<<"-Infinity\n";
            } else {
                cout<<dist[a][b]<<"\n";
            }
		}
		cout<<"\n";
	}
	return 0;
}
