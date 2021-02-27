#include <bits/stdc++.h>
using namespace std;
int main () {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  string f;
    priority_queue<int>maxHeap;
    priority_queue<int,vector<int>,greater<int> >minHeap;
    while (cin>>f) {
        if (f=="#"){
        if(maxHeap.size()<=minHeap.size())
        {
        printf ("%d\n",minHeap.top());
        minHeap.pop ();
        }
        else
        {
          printf ("%d\n",maxHeap.top());
           maxHeap.pop ();
		}
        if (maxHeap.size()<minHeap.size()) {
          maxHeap.push(minHeap.top());
          minHeap.pop();
        }
      }
      else{
      	int n;
      	istringstream(f)>>n;
        if (maxHeap.size() == 0 && minHeap.size() == 0)
          maxHeap.push(n);
        else{
          if (n >= maxHeap.top())
            minHeap.push(n);
          else
            maxHeap.push(n);

          if (maxHeap.size() < minHeap.size()){
            maxHeap.push(minHeap.top());
            minHeap.pop();
          }
          else if (maxHeap.size() > minHeap.size()){
            minHeap.push(maxHeap.top());
            maxHeap.pop();
          }
        }
      }
    }
    return 0;
}
