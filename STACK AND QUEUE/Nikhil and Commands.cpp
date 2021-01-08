# include <bits/stdc++.h>
using namespace std;
int main()
{
	int T;
	cin>>T;
	for(int m=1;m<=T;m++)
	{
		vector<string>a;
	    int N;
		cin>>N;
		for(int i=1;i<=N;i++)
		{
			string s;
			cin>>s;
			if(s=="pwd")
			{
				for(int j=0;j<a.size();j++)
				{
					cout<<"/"<<a[j];
	            }
	            cout<<"/"<<endl;
			}
			else if(s=="cd")
			{
				string path;
				cin>>path;
				if(path[0]=='/')
				{
					a.clear();
					path=path.substr(1,path.length());
				}
				for(int j=0;j<path.length();j++)
				{
					string temp;
					while(path[j]!='/' && j<path.length())
					{
						temp+=path[j];
						j++;
					}
					if(temp == ".." && a.size() > 0) {
						a.pop_back();
					}else{
						a.push_back(temp);
					}
				}
			}
		} 	
	}
	return 0;
}
