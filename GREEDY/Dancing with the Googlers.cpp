# include <bits/stdc++.h>
using namespace std;
int pass1(int N, int p, int i);
int find(int N, int S, int p);
int pass2(int N, int p, int i);
int a[111];
int main()
{
	int T;
	cin>>T;
	for(int m=1;m<=T;m++)
	{
		int N;
		int S;
		int p;
		cin>>N>>S>>p;
		for(int i=0;i<N;i++)
		{
			cin>>a[i];
		}
		cout<<"Case #"<<m<<": "<<find(N,S,p);
		cout<<endl;
	}
	return 0;
}
int find(int N, int S, int p)
{
	int count=0;
	int i;
	for(int i=0;i<N;i++)
	{
		if(pass1(N,p,i))
		{
			count++;
		}
		else if(pass2(N,p,i) && S>0)
		{
				count++;
				S--;
		}
	}
	return count;
}
int pass1(int N, int p, int i)
{
 int High = p;
 int Low = p - 1;
 if (Low<0)
 {
  Low = 0;
 }
 if (a[i]>=High+Low*2)
 {
  return 1;
 }
 else
 {
  return 0;
 }
}
int pass2(int N, int p, int i)
{
	 int High = p;
 int Low = p - 2;

 if (Low < 0)
 {
  Low = 0;
 }

 if((a[i] >= High + Low * 2))
 {
  return 1;
 }
 return 0;
}
