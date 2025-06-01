//given you can break k walls give the length of the shortest path 
//min no. of walls to break to reach the end - using 01 bfs
#include<bits/stdc++.h>
using namespace std;
using ii pair<int,int>;
int n,m,k;
string arr[1000];
#define F first
#define S second
#define INF=1e9
using state pair<ii,int>; // addition int for the no. of walls you can break 
int dist[1001][1001][11];
int dx=[0,1,-1,0];
int dy=[0,-1,1,0];

bool check_inside(int x, int y)
{
    if(x>=0&&y>=0&&x<n&&y<m) return 1;
    else return 0;
}

void bfs01(state st )
{
    for(int i=0;i<n;i++) for(int j=0;j<m;j++)for(int l=0;l<k;l++) dist[i][j][k]=INF;
    queue<state>q;
    q.push(st);
    dis[st.F.F][st.F.S][st.S]=0;   // state ka first ka first will give the first index 
    while(!dq.empty())
    {
        state cur=q.front();
        q.pop();
        //ecplore the neighbours of st
        for(int i =0;i<4;i++)
        {
             int nx=cur.F.F+dx[i];
             int ny=cur.F.S+dx[i];
             if(check_inside(nx,ny))
             {
                int nwall=cur.S+(arr[nx][ny]=='#'?1:0) ; // if it is # then add 1 other wise 0
                if(nwall>k) continue; // nwall can't be greater than k;
              
                if(dist[nx][ny][nwall]>dist[cur.F.F][cur.F.S][cur.S]+1)  // distance array initialized with inf , so if the dis[nx][ny] is not visited ie it is infinity then we increase the distance by 1
                {
                    dist[nx][ny][nwall]=dist[cur.F.F][cur.F.S][cur.S]+1;
                    q.push_back({{nx,ny},nwall} );
                }

                
                }
             }
        }
        
    }
}
int main ()
{
  cin>>n>>m>>k;
  ii st,en;
  for(int i=0;i<n;i++)
  {
    cin>>arr[i];
    for(int j=0;i<m;j++)
    {
        if(arr[i][j]=='S')
        {
            st={i,j};
        }

        if(arr[i][j]=='F')
        {
            en={i,j};
        }
    }
  }

  bfs01({st,0});  // initially broken 0 wall 
  int ans=INF;
  for(int i=0;i<k;i++)
  {
    ans=min(ans,dist[en.F.F][en.F.S][i]);

  }
  cout<<ans<<endl; 


    return 0;
}