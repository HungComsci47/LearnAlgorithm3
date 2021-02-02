/*HungVoCs47*/
# include <bits/stdc++.h>
using namespace std;
int n;
int floyd_warshall(vector<vector<int> >&number_of_ways)
{
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				number_of_ways[i][j]+=number_of_ways[i][k]*number_of_ways[k][j];
			}
		}
	}
	bool done=false;
    for(int i=1;i<=n;i++)
    {
    	for(int j=1;j<=n;j++)
    	{
    		if(number_of_ways[i][j]>=2)
    		{
    			done=true;
    			break;
			}
		}
	}
	if(done) cout<<"Yes\n";
	else cout<<"No\n";
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int testcases;
	cin>>testcases;
	for(int m=1;m<=testcases;m++)
	{
		cin>>n;
		vector<vector<int> >number_of_ways(n+1,vector<int>(n+1,0));
		for(int i=1;i<=n;i++)
		{
			int k;
		    cin>>k;
		    for(int j=1;j<=k;j++)
		    {
		    	int v;
		    	cin>>v;
		    	number_of_ways[i][v]=1;
			}
		}
		cout<<"Case #"<<m<<": ";
		floyd_warshall(number_of_ways);
	}
	return 0;
}
