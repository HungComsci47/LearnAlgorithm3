# include <bits/stdc++.h>
using namespace std;
int main()
{
    string StringName[2];
	for(int i=0;i<2;i++)
	{
		string Names;
		getline(cin,Names);
		StringName[i]=Names;
	}
	int ps1[26]={0};
	int ps11[26]={0};
	long long int leng1=StringName[0].length();
	long long int leng2=StringName[1].length();
	string p=StringName[0];
	string s=StringName[1];
	long long int count=0;
	for(int i=0;i<leng1;i++)
	{
		if(p[i]=='a')
		{
			ps1[0]++;
		}
        else if(p[i]=='b')
		{
		    ps1[1]++;
		}
		else if(p[i]=='c')
		{
			ps1[2]++;
		}
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
	}
	for(int i=0;i<leng2;i++)
	{
		if(s[i]=='a')
		{
			ps11[0]++;
		}
        else if(s[i]=='b')
		{
		    ps11[1]++;
		}
		else if(s[i]=='c')
		{
			ps11[2]++;
		}
		else if(s[i]=='d')
		ps11[3]++;
			else if(s[i]=='e')
			ps11[4]++;
				else if(s[i]=='f')
				ps11[5]++;
					else if(s[i]=='g')
					ps11[6]++;
						else if(s[i]=='h')
						ps11[7]++;
							else if(s[i]=='i')
							ps11[8]++;
								else if(s[i]=='j')
								ps11[9]++;
									else if(s[i]=='k')
									ps11[10]++;
									else if(s[i]=='l')
									ps11[11]++;
									else if(s[i]=='m')
									ps11[12]++;
									else if(s[i]=='n')
									ps11[13]++;
									else if(s[i]=='o')
									ps11[14]++;
									else if(s[i]=='p')
									ps11[15]++;
									else if(s[i]=='q')
									ps11[16]++;
									else if(s[i]=='r')
									ps11[17]++;
									else if(s[i]=='s')
									ps11[18]++;
									else if(s[i]=='t')
									ps11[19]++;
									else if(s[i]=='u')
									ps11[20]++;
									else if(s[i]=='v')
									ps11[21]++;
									else if(s[i]=='w')
									ps11[22]++;
									else if(s[i]=='x')
									ps11[23]++;
									else if(s[i]=='y')
									ps11[24]++;
									else if(s[i]=='z')
									ps11[25]++;
	}
	int sum=0;
	for(int i=0;i<26;i++)
	{
		sum+=abs(ps1[i]-ps11[i]);
	}
	cout<<sum;
	return 0;
}
