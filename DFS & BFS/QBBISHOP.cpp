# include <bits/stdc++.h>
using namespace std;
bool check(int n, int a, int b)
{
	if(a<1 || b<1 || a>n || b>n) return false;
	return true;
}
void BFS(int p, int q, int s, int t, int n, int visited[][204])
{
   int dx[4]={-1,-1,1,1};
   int dy[4]={-1,1,1,-1};
   queue<int>qx;
   queue<int>qy;
   int number_of_ways[n+1][n+1]={0};
   qx.push(p);
   qy.push(q);
   bool done=false;
   int toa_do_x;
   int toa_do_y;
   while(!qx.empty() && !qy.empty())
   {
         toa_do_x=qx.front();
         toa_do_y=qy.front();
        qx.pop(); qy.pop();
        if(toa_do_x==s && toa_do_y==t)
        {
        	done=true;
		}
        visited[toa_do_x][toa_do_y]=1;
        for(int i=1;i<=n;i++)
        {
                 if((visited[toa_do_x+i*dx[0]][toa_do_y+i*dy[0]]==0) && check(n,toa_do_x+i*dx[0],toa_do_y+i*dy[0]))
                 {
                 	qx.push(toa_do_x+i*dx[0]);
                 	qy.push(toa_do_y+i*dy[0]);
                 	visited[toa_do_x+i*dx[0]][toa_do_y+i*dy[0]]=1;
                    {
                    if(number_of_ways[toa_do_x+i*dx[0]][toa_do_y+i*dy[0]]==0)
                 	number_of_ways[toa_do_x+i*dx[0]][toa_do_y+i*dy[0]]=number_of_ways[toa_do_x][toa_do_y]+1;
				    }
                 }
                 else if((visited[toa_do_x+i*dx[0]][toa_do_y+i*dy[0]]==1) && check(n,toa_do_x+i*dx[0],toa_do_y+i*dy[0]))
                 {
                 	number_of_ways[toa_do_x+i*dx[0]][toa_do_y+i*dy[0]]=min(number_of_ways[toa_do_x][toa_do_y]+1,number_of_ways[toa_do_x+i*dx[0]][toa_do_y+i*dy[0]]);
				 }
                 else break;
		}
		for(int i=1;i<=n;i++)
        {
                 if((visited[toa_do_x+i*dx[1]][toa_do_y+i*dy[1]]==0) && check(n,toa_do_x+i*dx[1],toa_do_y+i*dy[1]))
                 {
                 	qx.push(toa_do_x+i*dx[1]);
                 	qy.push(toa_do_y+i*dy[1]);
                 	visited[toa_do_x+i*dx[1]][toa_do_y+i*dy[1]]=1;
                    {
                    if(number_of_ways[toa_do_x+i*dx[1]][toa_do_y+i*dy[1]]==0)
                 	number_of_ways[toa_do_x+i*dx[1]][toa_do_y+i*dy[1]]=number_of_ways[toa_do_x][toa_do_y]+1; 
                    }
                 }
                   else if((visited[toa_do_x+i*dx[1]][toa_do_y+i*dy[1]]==1) && check(n,toa_do_x+i*dx[1],toa_do_y+i*dy[1]))
                 {
                 	number_of_ways[toa_do_x+i*dx[1]][toa_do_y+i*dy[1]]=min(number_of_ways[toa_do_x][toa_do_y]+1,number_of_ways[toa_do_x+i*dx[1]][toa_do_y+i*dy[1]]);
				 }
                  else break;
		}
	    for(int i=1;i<=n;i++)
        {
                 if((visited[toa_do_x+i*dx[2]][toa_do_y+i*dy[2]]==0 && check(n,toa_do_x+i*dx[2],toa_do_y+i*dy[2])))
                 {
                 	qx.push(toa_do_x+i*dx[2]);
                 	qy.push(toa_do_y+i*dy[2]);
                 	visited[toa_do_x+i*dx[2]][toa_do_y+i*dy[2]]=1;
                    {
                    if(number_of_ways[toa_do_x+i*dx[2]][toa_do_y+i*dy[2]]==0)
                 	number_of_ways[toa_do_x+i*dx[2]][toa_do_y+i*dy[2]]=number_of_ways[toa_do_x][toa_do_y]+1; 
                    }
                    
                 }
                 else if((visited[toa_do_x+i*dx[2]][toa_do_y+i*dy[2]]==1) && check(n,toa_do_x+i*dx[2],toa_do_y+i*dy[2]))
                 {
                 	number_of_ways[toa_do_x+i*dx[2]][toa_do_y+i*dy[2]]=min(number_of_ways[toa_do_x][toa_do_y]+1,number_of_ways[toa_do_x+i*dx[2]][toa_do_y+i*dy[2]]);
				 }
                 else break;
		}
		for(int i=1;i<=n;i++)
        {
                 if(visited[toa_do_x+i*dx[3]][toa_do_y+i*dy[3]]==0 && check(n,toa_do_x+i*dx[3],toa_do_y+i*dy[3]))
                 {
                 	qx.push(toa_do_x+i*dx[3]);
                 	qy.push(toa_do_y+i*dy[3]);
                 	visited[toa_do_x+i*dx[3]][toa_do_y+i*dy[3]]=1;
                    {
                    if(number_of_ways[toa_do_x+i*dx[3]][toa_do_y+i*dy[3]]==0)
                 	number_of_ways[toa_do_x+i*dx[3]][toa_do_y+i*dy[3]]=number_of_ways[toa_do_x][toa_do_y]+1;
                    }
                 }
                  else if((visited[toa_do_x+i*dx[3]][toa_do_y+i*dy[3]]==1) && check(n,toa_do_x+i*dx[3],toa_do_y+i*dy[3]))
                 {
                 	number_of_ways[toa_do_x+i*dx[3]][toa_do_y+i*dy[3]]=min(number_of_ways[toa_do_x][toa_do_y]+1,number_of_ways[toa_do_x+i*dx[3]][toa_do_y+i*dy[3]]);
				 }
                 else break;
		}
	}
   if(!done) cout<<-1;
   else cout<<number_of_ways[s][t];
}
int main()
{ 
	int n,m,p,q,s,t;
	cin>>n>>m>>p>>q>>s>>t;
	int blocked_x[m+1];
	int blocked_y[m+1];
	for(int i=0;i<m;i++)
	{
		cin>>blocked_x[i]>>blocked_y[i];
	}
	int visited[204][204]={0};
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int k=0;k<m;k++)
			{
				if(i==blocked_x[k] && j==blocked_y[k])
				{
					visited[i][j]=-1;
				}
			}
		}
	}
	BFS(p,q,s,t,n,visited);
	return 0;
}
