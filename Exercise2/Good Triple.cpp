# include <bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	getline(cin,s);
	int n=s.length();
	int res=0;
	int count=n;
	for(int i=n-1;i>=0;i--)
	{
		for(int k=1;2*k+i<count;k++)
		{
			if(s[i]==s[i+k] && s[i+2*k]==s[i+k])
			{
				count=i+2*k;
				break;
			}
		}
		res+=n-count;
	}
	cout<<count;
	return 0;
}
