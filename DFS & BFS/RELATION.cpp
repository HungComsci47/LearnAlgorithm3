# include <bits/stdc++.h>
using namespace std;
void DFS(int V);
vector<int>a[200005];
bool ok[100005];
bool ok1[100005];
int main()
{
	for(int q=1;q<=3;q++)
	{
	int N,M;
	cin>>N>>M;
	int m[200005];
	for(int i=1;i<=2*M;i++)
	{
		cin>>m[i];
	}
	for(int i=1;i<=2*M;i+=2)
	{
		a[m[i]].push_back(m[i+1]);
	}
    for(int i=1;i<=N;i++)
    {
    	ok[i]=false;
    	ok1[i]=false;
	}
	bool done=true;
	for(int i=1;i<=N;i++)
	{
		for(int j=0;j<a[i].size();j++)
		{
		    	if(!ok[a[i][j]])
		    	{
		    		ok[a[i][j]]=true;
				}
				else
				{
					done=false;
					break;
				}
		}
		if(!done) break;
	}
	int dem=0;
	for(int i=1;i<=N;i++)
	{
		if(!ok1[i] )
		{
			dem++;
			DFS(i);
		}
	}
	cout<<"*"<<dem<<"*";
	bool done1=false;
	int sum=0;
	for(int i=1;i<=N;i++)
	{
		sum+=a[i].size();
	}
	cout<<sum;
	if(sum==N-dem) done1=true;
	if(done1 && done) cout<<1;
	else cout<<0; 
   }
	return 0;
}
void DFS(int V)
{
	ok1[V]=true;
	for(int i=0;i<a[V].size();i++)
	{
		if(!ok1[a[V][i]])
		{
			DFS(a[V][i]);
		}
	}
}

