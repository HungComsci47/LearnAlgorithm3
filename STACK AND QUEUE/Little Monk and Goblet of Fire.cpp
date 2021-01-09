# include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	string s;
	vector<int>q;
	vector<int>q1[50000];
	int dem;
	for(int i=1;i<=n;i++)
	{
		cin>>s;
		int a,b;
		if(s=="E")
		{
			cin>>a;
			cin>>b;
			dem=q.size();
			bool done=false;
			for(int j=0;j<dem;j++)
			{
				if(q[j]==a)
				{
					done=true;
				}
			}
			if(!done) q.push_back(a);
            q1[a].push_back(b);
             
             		
        }
		else if(s=="D")
		{
	        
			a=q.front();
	        b=q1[a].front();
			q1[a].erase(q1[a].begin());
			if(q1[a].empty())
			{
				q.erase(q.begin());
			}
			cout<<a<<" "<<b;
			cout<<endl;
		}
	}
	return 0;
}



