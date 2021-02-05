/*HungVoCs47*/
# include <bits/stdc++.h>
using namespace std;
typedef pair<int,int>ii;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n,r,a,b,t;
	cin>>t;
	for(int m=1;m<=t;m++)
	{
		cin>>n>>r;
		vector<ii>cities;
		for(int i=0;i<n;i++)
		{
			cin>>a>>b;
			cities.push_back(ii(a,b));
		}
		int state=1;
		double road=0,rail=0;
		vector<bool>taken(n);
		priority_queue<ii,vector<ii>,greater<ii> >pq;
		pq.push(ii(0,0));
		while(!pq.empty())
		{
			int cur,dist;
			dist=pq.top().first;
			cur=pq.top().second;
			pq.pop();
			if(taken[cur]) continue;
			if(sqrt(dist)>r)
			{
				rail+=sqrt(dist);
				state++;
			}
			else 
			{
				road+=sqrt(dist);
			}
			taken[cur]=true;
			bool all_taken=true;
			for(int i=0;i<n;i++)
			{
				if(!taken[i])
				{
					all_taken=false;
					int xDiff=cities[i].first-cities[cur].first;
				    int yDiff=cities[i].second-cities[cur].second;
					xDiff*=xDiff;
					yDiff*=yDiff;
					pq.push(ii(xDiff+yDiff,i));
				}
			}
			if(all_taken) break;
		}
		cout<<"Case #"<<m<<": ";
		cout<<state<<" "<<round(road)<<" "<<round(rail)<<"\n";
	}
	return 0;
}
