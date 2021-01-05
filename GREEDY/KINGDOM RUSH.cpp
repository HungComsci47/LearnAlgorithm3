#include <bits/stdc++.h>
using namespace std;
int main(){
	int t, n;
	pair<int,int> level[1005];
	int remain[1005];
	cin>>t;
	for(int i=0; i<t; i++){
		cin>>n;
		for(int j=0; j<1005; j++)
			remain[j] = 2;
		for(int j=0; j<n; j++)
			cin>>level[j].first>>level[j].second;
		int star = 0;
		int step = 0;
		while(star < 2*n){
			while(1){
				bool check = false;
				for(int j=0; j<n; j++){
					if((remain[j]>0) && (star>=level[j].second)){
						star += remain[j];
						remain[j] = 0;
						step++;
						check = true;
					}
				}
				if(check == false)
					break;
			}
			int tmp = -1;
			int index;
			for(int j=0; j<n; j++){
				if((remain[j]==2) && (star>=level[j].first)){
					if(level[j].second > tmp)
						index = j;
					tmp = max(tmp, level[j].second);
				}
			}
			if(tmp > -1){
				star++;
				remain[index]--;
				step++;
			}		
			else
				break;
		}
		if(star < 2*n)
			cout<<"Case #"<<(i+1)<<": Too Bad"<<endl;
		else
			cout<<"Case #"<<(i+1)<<": "<<step<<endl;
	}
	return 0;
}
