# include <bits/stdc++.h>
using namespace std;
void DFS(int V);
vector<int>a[100005];
bool ok[200005];
bool ok1[200005];
int main()
{
	for(int e=1;e<=3;e++)
	{
	int m[200005];
	int M;
	int N;
	cin>>N>>M;
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
	int decrease[100005]={0};
	for(int i=1;i<=N;i++)
	{
		for(int j=0;j<a[i].size();j++)
		{
			decrease[a[i][j]]=1;
		}
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
	bool done1=false;
	int sum=0;
	int dem=0;
	int dem2=0;
	for(int i=1;i<=N;i++)
	{
		if(!ok1[i] && decrease[i]==0)
		{
			dem++;
			DFS(i);
		}
	}
	for(int i=1;i<=N;i++)
	{
		if(!ok1[i])
		{
			dem2++;
			DFS(i);
		}
	}
	for(int i=1;i<=N;i++)
	{
		sum+=a[i].size();
	}
	if(sum==N-dem-dem2) done1=true;
	if(done & done1) cout<<1;
	else cout<<0;
	for(int i=1;i<=N;i++)
	{
		a[i].clear();
	}
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
