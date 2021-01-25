 /* HungVoCs47 */
# include <bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int testcases;
	cin>>testcases;
	while(testcases--)
	{
	string s;
	cin>>s;
	int n=s.length();
	s=" "+s;
	vector<int>l(2*n+1,-1);
  vector<int>r(2*n+1,0);
	l[n]=0;
	int ps=0;
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='1') ps++;
		else ps--;
		if(l[ps+n]==-1) l[ps+n]=i;
		r[ps+n]=i;
	}
	int res=0;
	int mn=n+1;
	for(int i=-n;i<=n;i++)
    {
          if(res<r[i+n]-mn) {
                res=r[i+n]-mn;
            }
          if(l[i+n]!=-1)
                mn=min(mn,l[i+n]);
	}
	cout<<res<<'\n';
    }
	return 0;
}
