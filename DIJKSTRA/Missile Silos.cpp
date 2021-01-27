/* HungVoCs47 */ 
#include <bits/stdc++.h>
using namespace std;
# define ll long long int
const int oo = 1000111000;
typedef pair<int, int> ii;
vector<ii>a[100005];
int n, m;
int d[100005];
int res=0;
int l;
void dijkstra(int capital) {
    priority_queue<ii, vector<ii>, greater<ii> > pq;
    for (int i = 1; i <= n; i++)
    d[i] = oo;
    d[capital] = 0;
    pq.push(ii(0, capital));
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
}
void check(int v, int u, int w)
{
	if(d[v]<l && d[u]<l && d[v]+d[u]+w==2*l) res++;
	if (d[u]<l && d[u]+w>l && d[u]+d[v]+w>2*l) res++;
    if (d[v] <l && d[v]+w>l && d[u]+d[v]+w>2*l) res++;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int capital;
    int p[100005], q[100005], w[100005];
    cin>>n>>m>>capital;
    for(int i=0;i<m;i++) {
        cin>>p[i]>>q[i]>>w[i];
        a[p[i]].push_back(ii(w[i], q[i]));
        a[q[i]].push_back(ii(w[i], p[i]));
    }
    cin>>l;
    dijkstra(capital);
    for(int i=1;i<=n;i++)
    {
    	if(d[i]==l) res++;
	}
    for(int i=0;i<m;i++)
    {
    	check(p[i],q[i],w[i]);
	}
	cout<<res;
    return 0;
}
