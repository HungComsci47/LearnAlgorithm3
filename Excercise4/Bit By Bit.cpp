# include <bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); 
	cin.tie(0);
	cout.tie(0);
	while(1)
	{
	int s[33];
	for(int i=0;i<=31;i++) s[i]=-1;
	int q;
	cin>>q;
	if(q==0) break;
	while(q--)
	{
		string S;
		cin>>S;
		if(S=="SET")
		{
			int a;
			cin>>a;
			s[a]=1;
		}
		if(S=="CLEAR")
		{
			int a;
			cin>>a;
			s[a]=0;
		}
		if(S=="OR")
		{
			int a,b;
			cin>>a>>b;
			if(s[a]==1 || s[b]==1) s[a]=1;
			else if(s[a]==-1 || s[b]==-1) s[a]=-1;
      else s[a]=0;
		}
		if(S=="AND")
		{
			int a,b;
			cin>>a>>b;
			if(s[a]==0 || s[b]==0) s[a]=0;
			else if(s[a]==-1 || s[b]==-1) s[a]=-1;
      else s[a]=1;
	    }
	}
	for(int i=31;i>=0;i--) 
	{
		if(s[i]==-1) cout<<"?";
		else 
	    cout<<s[i];
   }
	cout<<"\n";
    }
	return 0;
}
