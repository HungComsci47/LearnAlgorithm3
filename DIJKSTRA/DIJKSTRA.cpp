/*HungVoCs47*/
/*
INPUT:
5 6
1 2 2
2 5 5
2 3 4
1 4 1
4 3 3
3 5 1
OUTPUT:
1 4 3 5 
*/
#include <bits/stdc++.h>
using namespace std;
const int oo = 1000111000;
typedef pair<int, int> ii;
vector<ii>a[100005];
int n, m;
int d[100005];
int path[100005];
void dijkstra() {
    priority_queue<ii, vector<ii>, greater<ii> > pq;
    for (int i = 1; i <= n; i++)
    d[i] = oo;
    d[1] = 0;
    pq.push(ii(0, 1));
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
            	path[v]=u;
                d[v] = du + uv;
                pq.push(ii(d[v], v));
            }
        }
    }
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int p, q, w;
    cin>>n>>m;
    while (m--) {
        cin>>p>>q>>w;
        a[p].push_back(ii(w, q));
        a[q].push_back(ii(w, p));
    }
    dijkstra();
    if (d[n] == oo) cout << -1;
    else {
        int u = n;
        vector <int> a;
        do {
            a.push_back(u);
            u = path[u];
        } while (u != 0);
        for (int i = a.size() - 1; i>=0; i--) cout << a[i] <<' ';
    }
}
