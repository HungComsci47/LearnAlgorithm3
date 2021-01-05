# include <bits/stdc++.h>
using namespace std;
int main()
{
	int T;
	cin>>T;
	for(int m=1;m<=T;m++)
	{
		int n;
		cin>>n;
		char s1[n+200];
		char s2[n+200];
        for(int i=1;i<=n;i++)
	    {
	    	cin>>s1[i];
		}
		for(int i=1;i<=n;i++)
	    {
	    	cin>>s2[i];
		}
		s1[0]='X';
		s2[0]='X';
		s1[n+1]='X';
		s2[n+1]='X';
		int dem=0;
		for(int i=1;i<=n;i++)
		{
			if(s1[i-1]=='X' && s1[i+1]=='X' && s2[i]=='X' && s1[i]=='.')
			{
				s1[i]='G';
		        dem++;
			}
			 if(s2[i-1]=='X' && s2[i+1]=='X' && s1[i]=='X' && s2[i]=='.')
			{
				s2[i]='G';
				dem++;
			}
			 if(s2[i-1]=='X' && s2[i+1]=='X' && s1[i]=='.' && s2[i]=='.')
			{
			    s1[i]='G';
			    dem++;
			    s2[i]='T';
			}
			 if(s1[i-1]=='X' && s1[i+1]=='X' && s1[i]=='.' && s2[i]=='.')
			{
				s2[i]='G';
			    dem++;
			    s1[i]='T';
			}
			 if(s1[i+1]=='X' && s2[i+1]=='X' && s1[i]=='.' && s2[i]=='.'&& s1[i-1]=='X' && s2[i-1]=='X')
			{
				s1[i]='G';
			    dem++;
			    s2[i]='T';
			}
      			 if(s1[i+1]=='X' && s2[i+1]=='X' && s1[i]=='.' && s2[i]=='.'&& s1[i-1]=='X' && s2[i-1]=='X')
			{
				s2[i]='G';
			    dem++;
			    s1[i]='T';
			}
		}
	    int luu_vet_1[n+10];
	    int k1=0;
	    for(int i=0;i<=n+1;i++)
	    {
	    	if(s1[i]=='X')
	    	{
	    		luu_vet_1[k1]=i;
	    		k1++;
			}
		}
		int luu_vet_2[n+10];
		int k2=0;
		for(int i=0;i<=n+1;i++)
		{
			if(s2[i]=='X')
			{
				luu_vet_2[k2]=i;
				k2++;
			}
		}
		for(int i=0;i<k1-1;i++)
		{
			bool done=false;
			if(luu_vet_1[i+1]-luu_vet_1[i]>1)
			{
				for(int j=luu_vet_1[i]+1;j<luu_vet_1[i+1];j++)
				{
					if(s1[j]=='G' || s1[j]=='T')
					{
						done=true;
						break;
				    }
				}
				if(!done) dem++;
			}
		}
		for(int i=0;i<k2-1;i++)
		{
			bool done=false;
			if(luu_vet_2[i+1]-luu_vet_2[i]>1)
			{
				for(int j=luu_vet_2[i]+1;j<luu_vet_2[i+1];j++)
				{
					if(s2[j]=='G' || s2[j]=='T')
					{
						done=true;
						break;
					}
				}
				if(!done) dem++;
			}
		}
		cout<<"Case #"<<m<<": ";
		cout<<dem;
		cout<<endl;
	}
	return 0;
}










