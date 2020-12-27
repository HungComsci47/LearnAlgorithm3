#include <bits/stdc++.h> 
using namespace std; 
long long int maxXorSum(long long int n, long long int k) 
{ 
    if (k == 1) 
        return n; 
    long long int res = 1; 
    while (res <= n) 
        res <<= 1; 
    return res - 1; 
} 
int main() 
{ 
    long long int n,k;
    cin>>n>>k;
    cout << maxXorSum(n, k); 
    return 0; 
} 
