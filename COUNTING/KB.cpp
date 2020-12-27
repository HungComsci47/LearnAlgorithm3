#include<bits/stdc++.h>
using namespace std;

int main () {
    int n; cin >> n; cin.ignore();
    string s; cin >> s;
    int r = -1;
    if(s.size() <= 26){
        r = 0;
        int f[26]{};
        memset(f, 0, sizeof(f));
        for(char c : s) f[c-'a']++;
        for(int i = 0; i < 26; i++){
            if(f[i] > 1) r += f[i]-1;
        }
    }
    cout << r;
}
