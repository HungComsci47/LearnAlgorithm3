# include <bits/stdc++.h>
using namespace std;
int max( int a, long long int b);
bool OK(long long int C,long long int B,long long int T,long long int M[], long long int S[], long long int P[], long long int R );
int main()
{
	int T;
	cin>>T;
	for(int w=1;w<=T;w++)
	{
		long long int R;// number of robots;
		long long int B;// number of bits
		long long int C;// number of cashier
		cin>>R>>B>>C;
		long long int M[C];
		long long int S[C];
		long long int P[C];
		for(int i=1;i<=C;i++)
		{
			cin>>M[i]>>S[i]>>P[i];
		}
	  long long int left=0;
	  long long int right=2e18;	
      while(left<right)
      {
      	long long int mid=(left+right)/2;
      	if(OK(C,B,mid,M,S,P,R))
      	{
      	   	right=mid;
	    }
		else
		{
			left=mid+1;
		} 
	  }
	cout<<"Case #"<<w<<": ";
	cout<<left;
	cout<<endl;
	}
	return 0;
}
bool OK(long long int C,long long int B,long long int T,long long int M[], long long int S[], long long int P[], long long int R)
{
	long long int cur[C+1];
	for(int i=1;i<=C;i++)
	{
		long long int t=min((T - P[i])/S[i] , M[i]);
		cur[i]=max(0,t);
	}
	sort(cur+1,cur+C+1);
	long long int sum=0;
	for(int i=0;i<R;i++)
	{
		sum+=cur[C-i];
		if(sum>=B)
		{
			return true;
		}
	}
	return false;
}
int max( int a, long long int b)
{
	if(a<=b) return b;
	else return a;
}
