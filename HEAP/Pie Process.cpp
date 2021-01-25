/*HungVoCs47*/
# include <bits/stdc++.h>
using namespace std;
# define ll long long int
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int testcase;
	cin>>testcase;
	for(int p=1;p<=testcase;p++)
	{
		ll res=0;
		priority_queue<int,vector<int>,greater<int> >Q;
		int N;
		int M;
		cin>>N>>M;
		for(int i=0;i<N;i++)
		{
			ll a[340];
			for(int j=1;j<=M;j++)
			{
				cin>>a[j];
			}
			sort(a+1,a+M+1);
			for(int j=1;j<=M;j++)
			{
				a[j]+=j*j-(j-1)*(j-1);
				Q.push(a[j]);
			}
      ll t=Q.top();
			Q.pop();
			res+=t;
		}
		cout<<"Case #"<<p<<": "<<res<<'\n';
	}
	return 0;
}
