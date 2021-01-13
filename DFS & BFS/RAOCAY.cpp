#include <bits/stdc++.h>
using namespace std;
int visit(int ***A, int i, int j, int n, int m, int size, int ***B) {
    (*B)[i][j] = 0;
    if(*A[i-1][j]==1 && (*A[i+1][j]==0 && *A[i][j-1]==0 && *A[i][j+1]==0))
    {
        size+=3;
	}
	else if(*A[i+1][j]==1 && (*A[i-1][j]==0  &&  *A[i][j-1]==0  &&  *A[i][j+1]==0))
	{
		size+=3;
	}
	else if(*A[i][j-1]==1 && (*A[i+1][j]==0  &&  *A[i-1][j]==0  &&  *A[i][j+1]==0 ))
	{
		size+=3;
	}
	else if(*A[i][j+1]==1 && (*A[i+1][j]==0  &&  *A[i-1][j]==0  &&  *A[i][j-1]==0 ))
	{
		size+=3;
	}
	else if((*A[i-1][j]==1 && *A[i][j+1]==1 ) && (*A[i-1][j]==0  && *A[i][j+1]==0 ) )
	{
		size+=2;
	}
	else if((*A[i][j+1]==1 && *A[i+1][j]==1 ) && (*A[i-1][j]==0  && *A[i][j-1]==0 ) )
	{
		size+=2;
	}
	else if((*A[i+1][j]==1 && *A[i][j-1]==1 ) && (*A[i-1][j]==0  && *A[i][j+1]==0 ) )
	{
		size+=2;
	}
	else if((*A[i][j-1]==1 && *A[i-1][j]==1 ) && (*A[i+1][j]==0  && *A[i][j+1]==0 ) )
	{
		size+=2;
	}
	else if(*A[i-1][j]==1 && *A[i+1][j]==1  && *A[i][j-1]==1 && *A[i][j+1]==1)
	{
		size+=0;
	}
	else if(*A[i-1][j]==0 && (*A[i+1][j]==1 && *A[i][j-1]==1 && *A[i][j+1]==1))
	{
		size+=1;
	}
	else if(*A[i+1][j]==0 && (*A[i-1][j]==1  &&  *A[i][j-1]==1  &&  *A[i][j+1]==1 ))
	{
		size+=1;
	}
	else if(*A[i][j-1]==0 && (*A[i+1][j]==1  &&  *A[i-1][j]==1 &&  *A[i][j+1]==1 ))
	{
		size+=1;	
    }
	else if(*A[i][j+1]==0 && (*A[i+1][j]==1  &&  *A[i-1][j]==1  &&  *A[i][j-1]==1 ))
	{
		size+=1;
	}
    if(i-1 >= 0 && (*B)[i-1][j] == 1) {
        size += visit(A, i-1, j, n, m, 0,B);
    }
    if(j-1 >= 0 && (*B)[i][j-1] == 1) {
        size += visit(A, i, j-1, n, m, 0,B);
    }
    if(j+1 < m && (*B)[i][j+1] == 1) {
        size += visit(A, i, j+1, n, m, 0,B);
    }
    if(i+1 < n && (*B)[i+1][j] == 1) {
        size += visit(A, i+1, j, n, m, 0,B);
    }
    return size;
}

int main() {
	int n, m;
	cin>>n>>m;
	int **matrix = new int*[n];
	for(int i = 0; i < n; i++) {
		matrix[i] = new int[m];
		for(int j = 0; j < m; j++) {
			cin>>matrix[i][j];
		}
	}
	int **luu_vet=new int*[n];
	for(int i=0;i<n;i++)
	{
		luu_vet[i]=new int[m];
		for(int j=0;j<m;j++)
	     {
	     	luu_vet[i][j]=matrix[i][j];
		 }
	}
	int maxSize = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(matrix[i][j] == 1) {
				int size = visit(&luu_vet, i, j, n, m, 0, &matrix);
				maxSize+=size;
				}
			}
		}
	cout<<maxSize;
    return 0;
}


