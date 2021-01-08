# include <bits/stdc++.h>
using namespace std;
int main()
{
	stack<int>q;
	int Q;
	cin>>Q;
	int a,b;
    for(int i=1;i<=Q;i++)
	{
		cin>>a;
		if(a==1)
		{
			cin>>b;
			q.push(b);
		}
		else if(a==-1)
		{
			if(q.empty()) cout<<"kuchbhi";
			else
			cout<<q.top();
			q.pop();
			cout<<endl;
		}
	}
    return 0;
}
