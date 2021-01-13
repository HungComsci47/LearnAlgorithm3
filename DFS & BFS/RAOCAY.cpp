#include <bits/stdc++.h>
using namespace std;
int visit(int A[][1005], int i, int j, int n, int m, int size, int B[][1005]) {
    A[i][j] = 0;
    int temp=4;
    int a[4]={-1,0,1,0};
    int b[4]={0,1,0,-1};
    for(int k=0;k<=3;k++)
    {
    	if(B[i+a[k]][j+b[k]]==1)
    	{
    		temp--;
		}
    }
    size+=temp;
    if(i-1 >= 0 && A[i-1][j] == 1) {
        size += visit(A, i-1, j, n, m, 0,B);
    }
    if(j-1 >= 0 && A[i][j-1] == 1) {
        size += visit(A, i, j-1, n, m, 0,B);
    }
    if(j+1 < m && A[i][j+1] == 1) {
        size += visit(A, i, j+1, n, m, 0,B);
    }
    if(i+1 < n && A[i+1][j] == 1) {
        size += visit(A, i+1, j, n, m, 0,B);
    }
   return size;
}

int main(){
	int n, m;
	cin>>n>>m;
	int matrix[1005][1005];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++) {
			cin>>matrix[i][j];
		}
	}
	int luu_vet[1005][1005];
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			luu_vet[i][j]=matrix[i][j];
		}
	}
	int maxSize = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(matrix[i][j] == 1) {
				int z = visit(matrix, i, j, n, m, 0, luu_vet);
				maxSize+=z;
				}
			}
		}
	cout<<maxSize;
    return 0;
}

