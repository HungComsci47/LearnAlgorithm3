/*HungVoCs47*/
# include <bits/stdc++.h>
using namespace std;
# define ll long long int 
typedef priority_queue<ll,vector<ll>,greater<ll> >MinHeap;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int testcases;
	cin>>testcases;
	while(testcases--)
	{
		int N;
		cin>>N;
		ll sum=0;
		MinHeap Heap;
		for(int i=0;i<N;i++)
		{
		    ll x;
			cin>>x;
			Heap.push(x);
		}
		while(Heap.size()>1)
		{
			ll a=Heap.top(); Heap.pop();
			ll b=Heap.top(); Heap.pop();
			sum+=a+b;
			Heap.push(a+b);
		}
		cout<<sum<<"\n";
	}
	return 0;
}
