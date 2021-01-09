#include<bits/stdc++.h>
    using namespace std;
    int main()
    {
        int T,n,curr,mx;
        cin>>T;
        while(T--)
        {
            cin>>n;
            stack <int> s;
            vector <bool> in(n+1);
            mx=0;
            while(n--)
            {
                cin>>curr;
                if(mx<curr)
                {
                    cout<<curr<<" ";
                    ++mx;
                    while(mx<curr) s.push(mx++);
                    continue;
                }
                in[curr]=1;
                while(!s.empty() and in[s.top()]) 
                {
                    cout<<s.top()<<" ";
                    s.pop();
                }
            }
            while(!s.empty()) 
            {
                cout<<s.top()<<" ";
                s.pop();
            }
            cout<<"\n";
        }
        return 0;
    } 
