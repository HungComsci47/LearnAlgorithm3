#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	int t ;
	cin >> t ;
	while(t > 0)
	{
		int n;
		cin >> n;
		vector<int> A(n+5);
		string p;
		cin >> p;
		for(int i=0;i<n;i++)
			cin >> A[i];
		int an=0;
		int c=0 ;
		for(c=0;c<n;c++){
			if(p[c]=='1')
				break ;
		}
		an+=A[c]-A[0];
		for(;c<n;)
		{
			int f=0,j;
			for(int k=c+1;k<n;k++)
			{
				if(p[k]=='1'&&f==0)
				{
					j=k ;
					f=1 ;
					break;
				}

			}
			if(f==0) break;
			int m=0;
			for(int k=c+1;k<=j;k++)
			{
				if(A[k]-A[k-1]>m)
					m =A[k]-A[k-1];
			}
			an+=A[j]-A[c]-m;
			c=j;
		}
		an+=A[n-1]-A[c];
		cout << an << endl;
		t--;
	}

}


