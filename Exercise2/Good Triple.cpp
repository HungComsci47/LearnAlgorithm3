# include <bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	getline(cin,s);
	long long int res=0;
	long long int n=s.length();
  long long int cnt=n;
	for(int i=n-1;i>=0;i--)
	{
		for(int k=1;i+2*k<cnt;k++)
		{
		     if(s[i]==s[i+k] && s[i]==s[i+2*k])
		     {
		     	cnt=i+2*k;
		     	break;
			 }
		}
    res+=n-cnt;
	}
	cout<<res;
	return 0;
}
