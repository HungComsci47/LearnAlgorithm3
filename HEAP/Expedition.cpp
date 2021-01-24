/* HungVoCs47 */
#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
    	priority_queue<int>maxheap;
        int n, efa, cfa, tfs = 0;
        cin >> n;
        vector<pair<int,int> > arr(n + 2);
        for (int i = 0; i < n; ++i)
            cin >> arr[i].first >> arr[i].second;
        cin >> efa >> cfa;
        for (int i = 0; i < n; ++i)
            arr[i].first = efa - arr[i].first;
        arr[n] = make_pair(efa, 0);
        sort(arr.begin(), arr.end());
        for (int i = 0; i < arr.size(); ++i) {
            if (cfa >= efa)
                break;
            while (!maxheap.empty() && arr[i].first > cfa) {
                cfa +=maxheap.top(); maxheap.pop();
                tfs++;
            }
            if (arr[i].first > cfa)
                efa = 10000001;
            maxheap.push(arr[i].second);
        }
        if (cfa < efa)
            cout << -1 << endl;
        else
            cout << tfs << endl;
    }
    return 0;
}
