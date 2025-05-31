// here we will find the shortest path in an unweighted graph

// time complexity is O(n*m) = E+V 
//E = no. of edges = 4*n*m , V =n+
include<bits/stdc++.h>
using namespace std;

vector<string>g
vector<vector<char>>arr;
//input
/* 
6,6
S.#...
..#...
#.#.#.
....#.
####..
F..... 
*/
// may have spaces or not 

/* 
6,6
S . # . . .
. . # . . .
# . # . # .
. . . . # .
# # # # # .
F . . . . 
*/
#define F first
#define S second
#define INF 1e9
using state = pair<int,int>;
state st , en;
vector<vector<int>>dis;
vector<vector<int>>vis;
vector<vector<state>>par; // parent array to store the parent of the current state

bool isValid(int x,int y)
{
    if(x>=0 && y>=0 && x<n && y<m && arr[x][y]!='#')
    {
        return 1;
    }
    return 0;
}
s

// int the below function we are finding the neighbours of the current state , usig the is valid and also we explore all the 4 directions
vector<state> neighbours(state curr)
{
    vector<state>neighs;
    for(int i = 0; i < 4; i++)
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

void bfs(state node)
{
    queue<state>q;
    par.assign(n,vector<state>(m,{-1,-1}));
    // vis[node.F][node.S] = 1;
    dis[node.F][node.S] = 0;
    par[node.F][node.S] = {-1,-1};
        q.push(node);
        while(!q.empty())
        {
            state curr = q.front();
            q.pop();
            for(state v:neighbours(curr))
            {
                if(dis[v.F][v.S]==INF)  //  directly using the dis array to check if the node is visited or not , when dis is INF then it is not visited
                {
                    // vis[v.F][v.S] = 1;
                    dis[v.F][v.S] = dis[curr.F][curr.S] + 1;
                    par[v.F][v.S] = curr; // for the parent of the current state we are storing the current state 
                    q.push(v);
                }
            }
        }
}
 int main () {
    cin >> n >> m;//n is the number of nodes and m is the number of edges
    g.resize(n); // very important to resize the graph
    arr.resize(n);
    // when no space 
    for(int i = 0; i < n; i++) {
       cin>>g[i]
    }
    // when space is present 
    for(int i = 0; i < n; i++) {
        arr[i].resize(m);
       for(int j = 0; j < m; j++) {
        cin>>arr[i][j];
        if(arr[i][j]=='S')
        {
            start = {i,j};
        }
        if(arr[i][j]=='F')
        {
            end = {i,j};
        }
       }
    }

    // vis.assign(n,vector<int>(m,0));
    dis.assign(n,vector<int>(m,INF)); // distance of all the nodes is initialized to infinity
   bfs(st); // call the bfs for the starting node and the bfs will traverse the whole graph
   // printing the distance array 
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
  else 
  {
  cout<<dis[en.F][en.S]<<endl;
  //printing the path
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
