# include <bits/stdc++.h>
using namespace std;
int main()
{
  int N;
  int a[10000];
  cin>>N;
  int c[10000];
  int k=0;
  for(int i=0;i<N;i++)
  {
  	for(int j=0;j<N;j++)
  	{
  	  cin>>a[j];
  	}
	  sort(a,a+N);
  	  c[k]=a[(N)/2];
  	  k++;
  }
  sort(c,c+N);
  cout<<c[N/2];
  return 0;
}
