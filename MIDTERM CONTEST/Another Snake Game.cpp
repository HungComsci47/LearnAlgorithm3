#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin>>N;
	for(int m=1;m<=N;m++)
	{
	string p;
	cin>>p;
	int l=p.length();
	int i;
	int dem;
	int max=-1e3;
	for(int j=0;j<l;j++)
	{
		bool done=true;
		int ps1[26]={0};
		dem=0;
	    i=j;
	    while(i<l)
	    {
	    if(p[i]=='a')
	    ps1[0]++;
        else if(p[i]=='b')
	    ps1[1]++;
		else if(p[i]=='c')
	    ps1[2]++;
		else if(p[i]=='d')
		ps1[3]++;
		else if(p[i]=='e')
		ps1[4]++;
		else if(p[i]=='f')
		ps1[5]++;
		else if(p[i]=='g')
		ps1[6]++;
		else if(p[i]=='h')
		ps1[7]++;
		else if(p[i]=='i')
		ps1[8]++;
		else if(p[i]=='j')
		ps1[9]++;
		else if(p[i]=='k')
		ps1[10]++;
		else if(p[i]=='l')
		ps1[11]++;
		else if(p[i]=='m')
		ps1[12]++;
		else if(p[i]=='n')
		ps1[13]++;
		else if(p[i]=='o')
		ps1[14]++;
		else if(p[i]=='p')
		ps1[15]++;
		else if(p[i]=='q')
	    ps1[16]++;
		else if(p[i]=='r')
		ps1[17]++;
	    else if(p[i]=='s')
		ps1[18]++;
		else if(p[i]=='t')
		ps1[19]++;
		else if(p[i]=='u')
		ps1[20]++;
		else if(p[i]=='v')
		ps1[21]++;
	    else if(p[i]=='w')
		ps1[22]++;
		else if(p[i]=='x')
		ps1[23]++;
		else if(p[i]=='y')
		ps1[24]++;
		else if(p[i]=='z')
		ps1[25]++;
	    for(int k=0;k<26;k++)
	    {
	    	if(ps1[k]>=2) done=false;
		}
		if(!done) break;
		 dem++;
	     i++;
		}
		if(dem>max)
		{
			max=dem;
		}
	}
	cout<<max<<"\n";
    }
	return 0;
}
