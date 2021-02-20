#include <bits/stdc++.h>
using namespace std;
const int oo = 1000111000;
typedef pair<int,int>ii;
vector<ii>a[2309];
int n,m;
int s,t;
int d[2309];
int dijkstra(int s) {
    priority_queue<ii>pq;
    for(int i=1;i<=n;i++)
    d[i] = 0;
    d[s] = oo;
    pq.push(ii(oo, s));
    while (pq.size()) {
        int du = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if (du!=d[u])
            continue;

        for (int i = 0; i < a[u].size(); i++) {
            int v = a[u][i].second;
            int uv = a[u][i].first;
            int aa=min(uv,du);
            if (d[v]<aa) {
                d[v]=aa;
                pq.push(ii(d[v],v));
            }
        }
    }
    if(d[t]>0) return d[t];
    return -1;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int p, q, w;
    cin>>n>>m>>s>>t;
    while (m--) {
        cin>>p>>q>>w;
        a[p].push_back(ii(w, q));
        a[q].push_back(ii(w, p));
    }
    cout<<dijkstra(s);
    return 0;
}
