 #include <bits/stdc++.h>
using namespace std;
const int nxX[] ={+0,+0,+1,-1};
const int nxY[] = {+1,-1,+0,+0};
int m, n, a[1003][1003];
void dfs(int x,int y)
{
    for(int i=0;i<4;i++)
        {
            int X=nxX[i];
            int Y=nxY[i];

            if(x+X>=0 && x+X<=m+1 && y+Y>=0 && y+Y<=n+1 && a[x + X][y + Y]==0)
            {
                a[x+X][y+Y]=2;
                dfs(x+X,y+Y);
            }
        }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>m>>n;
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
            {
                char tmp;
                cin>>tmp;

                a[i][j]=tmp-'0';
            }

    a[0][0]=2;
    dfs(0,0);
    int seasize = 0;
    for(int i=0;i<=m+1;i++)
    {
        for(int j=0;j<=n+1;j++)
        {
        	cout<<a[i][j]<<" ";
		}
		cout<<"\n";
	}
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
            {
                if(a[i][j]!=1) continue;
                for(int t=0;t<4;t++)
                {
                    if(a[i+nxX[t]][j+nxY[t]]==2) seasize++;
                }
            }

    cout<<seasize;
    return 0;
}
