# include <bits/stdc++.h>
using namespace std;
int main()
{
	int T;
	cin>>T;
	for(int m=1;m<=T;m++)
	{
		int N;
		cin>>N;
		int a[N+1];
		for(int i=0;i<N;i++)
		{
			cin>>a[i];
		}
	     int res=0;
	     int cur=0;
	     for(int i=0;i<N;i++)
	    {
	         if(cur>0 && a[i]<=a[i-1])
	         {
	         	res+=4-cur;
	         	cur=1;
			 }
			 else if( cur>0 && a[i]-a[i-1]>10)
			 {
			 	int delta=a[i]-a[i-1];
			 	int need=4-cur;
			 	int add=(delta-1)/10;
			 	if(need>add)
			 	{
			 		res+=add;
			 		cur=(cur+add+1)%4;
			 	}
			 	else
			    {
			    	res+=need;
			    	cur=1;
				}
			 }
			 else 
			 {
			 	cur++;
				cur%=4;
			 }
		}
		if(cur>0)
		res+=4-(cur%4);
		cout<<"Case #"<<m<<": ";
		cout<<res;
		cout<<endl;
	}
	return 0;
}
