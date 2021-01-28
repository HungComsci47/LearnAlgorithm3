/* HungVoCs47 */
#include<bits/stdc++.h>
using namespace std;
char par[150];
char find(char x)
{
	if(par[x]==x) return par[x];
	return par[x]=find(par[x]);
}
void makeunion(char a, char b)
{
	char parx=find(a),pary=find(b);
	if(parx==pary) return;
	if(parx<pary)
	par[pary]=parx;
	else par[parx]=pary;
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string a,b,c;
	cin>>a>>b>>c;
	for(char i='a';i<='z';i++)
	{
		par[i]=i;
	}
	for(int i=0;i<a.length();i++)
	{
		makeunion(a[i],b[i]);
	}
	for(int i=0;i<c.length();i++)
	{
		cout<<find(c[i]);
	}
	return 0;
}
