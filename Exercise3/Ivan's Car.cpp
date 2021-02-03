/*HungVoCs47*/
#include <bits/stdc++.h>
using namespace std;
const int oo = 1000111000;
struct Edge{
 	int d,u,w;
 	Edge(int d=0,int u=0,int w=0):d(d),u(u),w(w){
	 }
};
bool operator > (const Edge &A, const Edge &B) {
	return A.d>B.d;
}
typedef pair<int,int>ii;
vector<ii>a[100005];
int n, m;
int dist[100005][2];
void dijkstra(int s) {
    priority_queue<Edge, vector<Edge>, greater<Edge> > pq;
    for (int i = 1; i <= n; i++)
    {
    dist[i][0] = oo;
    dist[i][1] = oo;
    }
    dist[s][0] = 0;
    dist[s][1] = 0;
    pq.push(Edge(0,s,0));
    pq.push(Edge(0,s,1));
    while (pq.size()) {
        int d = pq.top().d;
        int u = pq.top().u;
        int w = pq.top().w;
        pq.pop();
        for (int i = 0; i < a[u].size(); i++) {
            int val;
            int v=a[u][i].second;
            int state=a[u][i].first;
            if(w!=state && u!=s) val=1;
            else val=0;
            if(dist[v][state]>dist[u][w]+val)
            {
            	//cout<<u<<" "<<v;
            	dist[v][state]=dist[u][w]+val;
            	pq.push(Edge(dist[v][state],v,state));
			}
            }
        }
    }

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    int p, q, w;
    cin>>n>>m;
    while(m--){
        cin>>p>>q;
        a[p].push_back(ii(1, q));
        a[q].push_back(ii(0, p));
    }
    int s,e;
    cin>>s>>e;
    dijkstra(s);
    cout<<min(dist[e][0],dist[e][1]);
}
