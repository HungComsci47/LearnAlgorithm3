# include <bits/stdc++.h>
using namespace std;
const int MAXN=1005;
# define fi first
# define se second
int n,m;
int s1,c1,s2,c2;
char s[MAXN][MAXN];
bool visited[MAXN][MAXN];
typedef pair<int,int>ii;
int parent[MAXN][MAXN];
void makeset()
{
	for(int i=1;i<=1005;i++)
	     for(int j=1;j<=1005;j++)
		 { 
	       parent[i][j]=MAXN;
	       parent[i][j]=MAXN;
	     }
}
void bfs_decimal(int u, int v, int cnt)
{
	int dx[4]={-1,0,1,0};
	int dy[4]={0,1,0,-1};
	queue<ii>q;
	q.push(ii(u,v));
	while(!q.empty())
	{
		int a=q.front().fi;
		int b=q.front().se;
		q.pop();
        if(visited[a][b]) continue;
        parent[a][b]=cnt;
		visited[a][b]=true;
		for(int i=0;i<4;i++)
		{
			if(!visited[a+dx[i]][b+dy[i]] && s[a+dx[i]][b+dy[i]]=='1')
			{
				q.push(ii(a+dx[i],b+dy[i]));
			}
		}
	}
}
void bfs_binary(int u, int v, int cnt)
{
	int dx[4]={-1,0,1,0};
	int dy[4]={0,1,0,-1};
	queue<ii>q;
	q.push(ii(u,v));
	while(!q.empty())
	{
		int a=q.front().fi;
		int b=q.front().se;
		q.pop();
    if(visited[a][b]) continue;
		visited[a][b]=true;
		parent[a][b]=cnt;
		for(int i=0;i<4;i++)
		{
			if(!visited[a+dx[i]][b+dy[i]] && s[a+dx[i]][b+dy[i]]=='0')
			{
				q.push(ii(a+dx[i],b+dy[i]));
			}
		}
	}
}
int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  makeset();
  cin>>n>>m;
  for(int i=1;i<=n;i++)
   for(int j=1;j<=m;j++)
     cin>>s[i][j];
  for(int i=1;i<=n;i++)
	   for(int j=1;j<=m;j++)
	      visited[i][j]=false;
  int cnt_decimal=-1;
  for(int i=1;i<=n;i++)
  {
  	for(int j=1;j<=m;j++)
  	{
    if(!visited[i][j] && s[i][j]=='1')
    {
    	cnt_decimal++;
    	bfs_decimal(i,j,cnt_decimal);
    }
  }
  }
    for(int i=1;i<=n;i++)
	   for(int j=1;j<=m;j++)
	      visited[i][j]=false;
 for(int i=1;i<=n;i++)
  {
  	for(int j=1;j<=m;j++)
  	{
    if(!visited[i][j] && s[i][j]=='0')
    {
    	cnt_decimal++;
    	bfs_binary(i,j,cnt_decimal);
    }
  }
}
  int q;
  cin>>q;
  while(q--)
  {
    cin>>s1>>c1>>s2>>c2;
  	if(s[s1][c1]==s[s2][c2] && s[s1][c1]=='1' && parent[s1][c1]==parent[s2][c2]) cout<<"decimal\n";
  	else if(s[s1][c1]==s[s2][c2] && s[s1][c1]=='0' && parent[s1][c1]==parent[s2][c2]) cout<<"binary\n";
  	else cout<<"neither\n";
  }
  return 0;	
} 
