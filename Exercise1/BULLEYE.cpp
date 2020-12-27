# include <bits/stdc++.h>
using namespace std;
int main()
{
	int T;
	cin>>T;
	for(int m=1;m<=T;m++)
	{
		long long int r;
		long long int t;
		cin>>r>>t;
	 long long int left=0;
	 long long int right=t;
	 long long int mid;
	 long long int rx=-1e17;
	 long long int rx1=1e17;
      while(left+1<=right)
	    {
	    mid=(left+right)/2;
        if(mid<t/(2*r+1-2+2*mid))
	    {
	    	left=mid+1;
	    	rx=max(rx,mid);
	    }
	    if(mid>t/(2*r+1-2+2*mid))
	    {
	    	right=mid-1;
	    	rx1=min(rx1,mid);
	    }
	    if(mid==t/(2*r+1-2+2*mid))
	    {
	    	break;
	    }
	 }
	 long long int MAX=-1e17;
	 long long int check=0;
      cout<<"Case #"<<m<<": ";
      if(mid==t/(2*r+1-2+2*mid)) cout<<mid;
	  else if(rx==-1e17 && rx1!=1e17)
	  {
	  	cout<<rx1/2;
	  }
	  else if(rx!=-1e17 && rx1==1e17)
	  {
	  	cout<<rx/2;
	  }
	  else
	  {
	  	for(int i=rx;i<=rx1;i++)
	  	{
	  		if(i<=t/(2*r+1+2*i-2) && i>MAX)
	  		{
	  			MAX=i;
			}
		}
		cout<<MAX;
	  }
	  cout<<endl;
	}
	return 0;
}

