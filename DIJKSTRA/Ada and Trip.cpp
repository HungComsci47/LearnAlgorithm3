/*HungVoCs47*/
#include <bits/stdc++.h>
using namespace std;
const int oo = 1000111000;
typedef pair<int, int> ii;
vector<ii>a[500005];
int n, m;
int d[500005];
ii dijkstra(int s) {
    priority_queue<ii, vector<ii>, greater<ii> > pq;
    for (int i = 0; i < n; i++)
    d[i] = oo;
    d[s]=0;
    pq.push(ii(0, s));
    while (pq.size()) {
        int u = pq.top().second;
        int du = pq.top().first;
        pq.pop();
        if (du != d[u])
            continue;

        for (int i = 0; i < a[u].size(); i++) {
            int v = a[u][i].second;
            int uv = a[u][i].first;
            if (d[v] > du + uv) {
                d[v] = du + uv;
                pq.push(ii(d[v], v));
            }
        }
    }
    int distance=-1;
    int cnt=0;
    for(int i=0;i<n;i++)
    {
    	if(d[i]!=oo && d[i]>distance)
		{
			distance=d[i];
			cnt=1;
		}
		else if(d[i]==distance) cnt++;  
	}
	return ii(distance,cnt);
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    int p, q, w;
    int Q;
    cin>>n>>m>>Q;
    while (m--){
        cin>>p>>q>>w;
        a[p].push_back(ii(w, q));
        a[q].push_back(ii(w, p));
    }
    for(int i=0;i<Q;i++)
    {
    	int s;
    	cin>>s;
    	ii result=dijkstra(s);
    	cout<<result.first<<" "<<result.second<<"\n";
	}
    return 0;
}
