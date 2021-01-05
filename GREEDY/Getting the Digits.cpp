# include <bits/stdc++.h>
using namespace std;
# define ll long long int;
int main(){
	int T;
	cin>>T;
	for(int q=1;q<=T;q++)
	{
	string s;
	cin>>s;
    int n=s.length();
    int ps1[15]={0};
    for(int i=0;i<n;i++)
    {
             if(s[i]=='E') ps1[0]++;
        else if(s[i]=='F') ps1[1]++;
        else if(s[i]=='G') ps1[2]++;
        else if(s[i]=='H') ps1[3]++;
        else if(s[i]=='I') ps1[4]++;
        else if(s[i]=='N') ps1[5]++;
        else if(s[i]=='T') ps1[6]++;
        else if(s[i]=='R') ps1[7]++;
        else if(s[i]=='O') ps1[8]++;
        else if(s[i]=='Z') ps1[9]++;
        else if(s[i]=='W') ps1[10]++;
        else if(s[i]=='U') ps1[11]++;
        else if(s[i]=='V') ps1[12]++;
        else if(s[i]=='S') ps1[13]++;
        else if(s[i]=='X') ps1[14]++;
    }
    int dem_so_0=0;
    if(ps1[9]!=0){
	dem_so_0+=ps1[9];
	ps1[0]-=ps1[9];
	ps1[7]-=ps1[9];
	ps1[8]-=ps1[9];
    }
	int dem_so_2=0;
	if(ps1[10]!=0)
	{
	dem_so_2+=ps1[10];
	ps1[6]-=ps1[10];
	ps1[8]-=ps1[10];
	}
	int dem_so_6=0;
	if(ps1[14]!=0)
	{
		dem_so_6+=ps1[14];
		ps1[4]-=ps1[14];
		ps1[13]-=ps1[14];
	}
	int dem_so_8=0;
	if(ps1[2]!=0)
	{
		dem_so_8+=ps1[2];
		ps1[0]-=ps1[2];
		ps1[4]-=ps1[2];
		ps1[3]-=ps1[2];
		ps1[6]-=ps1[2];
	}
	int dem_so_3=0;
	if(ps1[3]!=0)
	{
		dem_so_3+=ps1[3];
		ps1[6]-=ps1[3];
		ps1[7]-=ps1[3];
		ps1[0]-=2*ps1[3];
	}
	int dem_so_4=0;
	if(ps1[7]!=0)
	{
		dem_so_4+=ps1[7];
		ps1[1]-=ps1[7];
		ps1[8]-=ps1[7];
		ps1[11]-=ps1[7];
	}
	int dem_so_5=0;
	if(ps1[1]!=0)
	{
		dem_so_5+=ps1[1];
		ps1[4]-=ps1[1];
		ps1[12]-=ps1[1];
		ps1[0]-=ps1[1];
	}
	int dem_so_7=0;
	if(ps1[12]!=0)
	{
		dem_so_7+=ps1[12];
		ps1[13]-=ps1[12];
		ps1[0]-=ps1[12]*2;
		ps1[5]-=ps1[12];
	}
	int dem_so_9=0;
	if(ps1[4]!=0)
	{
		dem_so_9+=ps1[4];
		ps1[5]-=ps1[4]*2;
		ps1[0]-=ps1[4];
	}
	int dem_so_1=0;
	if(ps1[8]!=0)
	{
		dem_so_1+=ps1[8];
	}
	int dem_0[n];
	for(int i=0;i<dem_so_0;i++) dem_0[i]=0;
	int dem_1[n];
	for(int i=0;i<dem_so_1;i++) dem_1[i]=1;
	int dem_2[n];
	for(int i=0;i<dem_so_2;i++) dem_2[i]=2;
	int dem_3[n];
	for(int i=0;i<dem_so_3;i++) dem_3[i]=3;
	int dem_4[n];
	for(int i=0;i<dem_so_4;i++) dem_4[i]=4;
	int dem_5[n];
	for(int i=0;i<dem_so_5;i++) dem_5[i]=5;
	int dem_6[n];
	for(int i=0;i<dem_so_6;i++) dem_6[i]=6;
	int dem_7[n];
	for(int i=0;i<dem_so_7;i++) dem_7[i]=7;
	int dem_8[n];
	for(int i=0;i<dem_so_8;i++) dem_8[i]=8;
	int dem_9[n];
	for(int i=0;i<dem_so_9;i++) dem_9[i]=9;
	cout<<"Case #"<<q<<": ";
	for(int i=0;i<dem_so_0;i++) cout<<dem_0[i];
	for(int i=0;i<dem_so_1;i++) cout<<dem_1[i];
		for(int i=0;i<dem_so_2;i++) cout<<dem_2[i];
			for(int i=0;i<dem_so_3;i++) cout<<dem_3[i];
				for(int i=0;i<dem_so_4;i++) cout<<dem_4[i];
					for(int i=0;i<dem_so_5;i++) cout<<dem_5[i];
						for(int i=0;i<dem_so_6;i++) cout<<dem_6[i];
							for(int i=0;i<dem_so_7;i++) cout<<dem_7[i];
								for(int i=0;i<dem_so_8;i++) cout<<dem_8[i];
									for(int i=0;i<dem_so_9;i++) cout<<dem_9[i];
	  cout<<endl;
   }
	return 0;
}
