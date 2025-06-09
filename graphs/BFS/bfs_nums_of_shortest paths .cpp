include<bits/stc++.h>
using namespace std;
const int INF=1e9;
#define F first
#define S second
using state=pair<int,int>;
state st,en;
vector<vector<int>>dis;
vector<vector<int>>vis;
vector<vector<state>>par;
vector<vector<int>>num_paths;  // counts the no. of shortest path from start to end 
vector<vector<int>>arr;

int n , m;

bool isValid(int x,int y)
{
    if(x>=0 && y>=0 && x<n && y<m && arr[x][y]!='#')
    {
        return 1;
    }
    return 0;
}


int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

vector<state>neighbours(state curr)
{
    vector<state>neighs;
    num_path.assign(n,vector<int>(m,INF));  // intialised with inf 
    for(int i=0;i<4;i++)
    {
        int x=curr.F+dx[i];
        int y=curr.S+dy[i];
        if(isValid(x,y))
        {
            neighs.push_back({x,y});
        }
    }
    return neighs;
}
void bfs(state sc_node)
{
    queue<state>q;
    par.assign(n,vector<state>(m,{-1,-1}));
    dis[sc_node.F][sc_node.S]=0;
    par[sc_node.F][sc_node.S]={-1,1};
    num_path[sc_node.F][sc_node.S]=1 ; // initially one path as we are startigng 
    q.push(node);
    while(!q.empty())
    {
        state curr=q.front();
        q.pop();
        for(state v:neighbours[curr])
        {
            if(dis[v.F][v.S]==INF)
             {
                
                dis[v.F][v.S]=1+dis[curr.F][curr.S];
                par[v.F][v.s]=curr;
                num_path[v.F][v.S]=num_path[curr.F][curr.S];
                q.push(v);
             }

             else if(dis[v.F][v.S]==1+dis[curr.F][curr.S])
             {
                 num_path[v.F][v.S]+=num_path[curr.F][curr.S];
             }
        }
        
        
    }
    
}
int main()
{
    cin>>n>>m;
    arr.resize(n);
    for(int i =0;i<n;i++)
    {
        arr[i].resize(m);
        for(int j=0;j<m;j++)
        {
            cin>>arr[i][j];
        }
        if(arr[i][j]=='S')
        {
            st={i,j};
        }

        if(arr[i][j]=='F')
        {
            en={i,j};
        }
    }

   dis.assign(n,vector<int>(m,INF));
   bfs(st);
    for(int i = 0; i < n; i++)
   {
    for(int j = 0; j < m; j++)
    {
        cout<<dis[i][j]<<" ";
    }
    cout<<endl;
   }


  if(dis[en.F][en.S]==INF)
    cout << "No path found" << endl;
  else <<
  {
  cout<<dis[en.F][en.S]<<endl;
  vector<state>path;
  state cur=en;
  while(cur!=make_pair(-1,-1))
  {
    path.push_back(cur);
    cur=par[cur.F][cur.S];

  }

  reverse(path.begin(),path.end());
  
  for(state v:path)
  {
    cout<<v.F<<" "<<v.S<<endl;
  }


  }


    return 0;
}