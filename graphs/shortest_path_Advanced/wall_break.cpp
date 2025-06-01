//min no. of walls to break to reach the end - using 01 bfs
#include<bits/stdc++.h>
using namespace std;
using ii pair<int,int>;
int n,m;
string arr[1000];
#define F first
#define S second
#define INF=1e9
using state ii;
int dist[1001][1001];
int dx=[0,1,-1,0];
int dy=[0,-1,1,0];

bool check_inside(int x, int y)
{
    if(x>=0&&y>=0&&x<n&&y<m) return 1;
    else return 0;
}

void bfs01(state st )
{
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) dist[i][j]=INF;
    deque<state>dq;
    dq.push_front(st);
    dis[st.F][st.S]=0; 
    while(!dq.empty())
    {
        state cur=dq.front();
        dq.pop_front();
        //ecplore the neighbours of st
        for(int i =0;i<4;i++)
        {
             int nx=cur.F+dx[i];
             int ny=cur.S+dx[i];
             if(check_inside(nx,ny))
             {
                if(arr[nx][ny]='#')
                {
                //cost1
                if(dist[nx][ny]>dist[cur.F][cur.S]+1)  // distance array initialized with inf , so if the dis[nx][ny] is not visited ie it is infinity then we increase the distance by 1
                {
                    dist[nx][ny]=dist[cur.F][cur.S]+1;
                    dq.push_back({nx,ny});
                }

                
                }

                else
                {
                    //cost 0
                    if(dist[nx][ny]>dist[cur.F][cur.S])
                    {
                        dist[nx][ny]=dist[cur.F][cur.S];
                    dq.push_back({nx,ny});
                    }
                     
                }
             }
        }
        
    }
}
int main ()
{
  cin>>n>>m;
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

  bfs01(st);
  cout<<dist[en.F][en.S]<<endl;


    return 0;
}