/*You are selling beautiful geometric pictures. Each one consists of 1x11x1 square tiles arranged into a non-overlapping grid. For example:

.##..
.####
.####
.##..
Blue tiles are represented by # characters, and white tiles are represented by . characters. You do not use other colors.

Not everybody likes blue though, and some customers want you to replace all the blue tiles in your picture with red tiles. Unfortunately, red tiles only come in the larger 2x22x2 size, which makes this tricky.

Not everybody likes blue though, and some customers want you to replace all the blue tiles in your picture with red tiles. Unfortunately, red tiles only come in the larger 2x22x2 size, which makes this tricky.

./\..
.\//\
./\\/
.\/..
Each red tile is represented here by a pair of / characters in the top-left and bottom-right corners, and a pair of \ characters in the other two corners.

Given a blue and white picture, can you transform it into a red and white picture in this way?

D? li?u nh?p
The first line of the input gives the number of test cases, T. TT.T test cases follow.
Each test case begins with a line containing RR and CC, the number of rows and columns in a picture. The next RR lines each contain exactly CC characters, describing the picture. As above, # characters represent blue tiles, and . characters represent white tiles.*/
# include <bits/stdc++.h>
using namespace std;
int main()
{
	int f;
	cin>>f;
	int t=1;
	do
	{
	int m,n;
	char a[60][60];
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>a[i][j];
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(a[i][j]=='#' && i+1<=n-1 && j+1<=m-1 && a[i+1][j]=='#' && 	a[i][j+1]=='#' && a[i+1][j+1]=='#' )
			{
				a[i][j]='/'       ;
				a[i+1][j]='\\'     ;
				a[i][j+1]='\\'     ;
				a[i+1][j+1]='/'   ;
		    }
	    }
	}
	int dem=0;
    for(int i=0;i<n;i++)
    {
    	for(int j=0;j<m;j++)
    	{
    		if(a[i][j]=='#')
    		{
    			dem++;
			}
	    }   
	}
	cout<<"Case #"<<t<<":"<<endl;
	if(dem==0)
	{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cout<<a[i][j];
	    }
	    cout<<endl;
	}
    }
    else
    {
    	cout<<"Impossible";
	}
	t++;
	cout<<endl;
	}while(t<=f);
	return 0;
}


