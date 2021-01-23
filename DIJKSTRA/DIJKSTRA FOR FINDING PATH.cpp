// Input
7 13
1 2 12
1 3 15
1 7 4
2 3 3 
2 6 11
3 6 9 
4 5 4 
4 6 20
4 7 5
5 2 1
5 6 13
7 2 7
7 5 6
//
//Output
0 11 4 9 10 22 4
//
#include <bits/stdc++.h>
using namespace std;
const int oo = 1000111000;
typedef pair<int, int> ii;
vector<ii>a[2309];
int n, m;
int d[2309];
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
                d[v] = du + uv;
                pq.push(ii(d[v], v));
            }
        }
    }
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int p, q, m, w;
    cin>>n>>m;
    while (m--) {
        cin>>p>>q>>w;
        a[p].push_back(ii(w, q));
        a[q].push_back(ii(w, p));
    }
    dijkstra();
    for (int i = 1; i <= n; i++)
        cout<<d[i]<<" ";
}
