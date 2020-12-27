# include <bits/stdc++.h>
using namespace std;
int main()
{
	int T;
	cin>>T;
	for(int m=1;m<=T;m++)
	{
		long long N;
		cin>>N;
		long long a[N+1];
		for(int i=0;i<N;i++)
		{
			cin>>a[i];
		}
		long long sum=0;
		for(int i=0;i<N;i++)
		{
			sum+=a[i];
		}
		sort(a,a+N);
		int XOR=a[0];
		for(int i=1;i<N;i++)
		{
			XOR=XOR^a[i];
		}
		cout<<"Case #"<<m<<": ";
		if(XOR==0) cout<<sum-a[0];
		else cout<<"NO";
		cout<<endl;
    }
	return 0;
}
