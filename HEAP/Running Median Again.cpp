# include <bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		priority_queue<int>MaxHeap;
		priority_queue<int>MaxHeap1;
		while(1)
		{
			int n;
			cin>>n;
            if(n==0) break;
			else if(n!=-1 && n!=0)
			{
				MaxHeap.push(n);
			}
			else if(n==-1)
			{
				int k=MaxHeap.size();
			    k=k/2;
				while(k>0)
				{
					int lay_phan_tu_trong_MaxHeap=MaxHeap.top();
					MaxHeap.pop();
					MaxHeap1.push(lay_phan_tu_trong_MaxHeap);
					k--;
				}
				int m=MaxHeap.top();MaxHeap.pop();
				cout<<m<<"\n";
				int t1=MaxHeap1.size();
				while(t1>0)
				{
					int g=MaxHeap1.top();MaxHeap1.pop();
					MaxHeap.push(g);
					t1--;
				}
			}
		}
	}
	return 0;
}
