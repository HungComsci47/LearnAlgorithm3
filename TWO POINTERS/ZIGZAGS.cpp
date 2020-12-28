# include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	for(int m=1;m<=t;m++)
	{
		int n;
		cin>>n;
		int a[n+1];
	    for(int i=1;i<=n;i++)
	    {
	    	cin>>a[i];
	    }
	    int CountLeft[n+1]={0};
	    int res=0;
	    for(int j=1;j<=n;j++)
	    {
	    	int CountRight[n+1]={0};
	    	for(int k=n;k>j;k--)
	    	{
	    		res+=CountLeft[a[k]]*CountRight[a[j]];
	    		CountRight[a[k]]++;
			}
			CountLeft[a[j]]++;
		}
		cout<<res;
}
 return 0;
}
	    
