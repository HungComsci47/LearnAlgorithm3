#include<bits/stdc++.h>
using namespace std;

int main()
{
 int n; 
 cin>>n;
 string s;  
 cin>>s;
 int k=0,ans=n;
 for(int i=0;i<n;i++)if(s[i]=='T')k++;
 for(int i=0;i<n;i++)
 {
   int m=0;
   for(int j=0;j<k;j++)
   {
   if(s[(i+j)%n]=='H')
   m++;
   }
   ans=min(ans,m);
 }
  cout<<ans;
  return 0;
}
