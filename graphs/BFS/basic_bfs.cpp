include<bits/stdc++.h>
using namespace std;

    int n,m ;
    vector<vector<int>>g;
    vector<int>visited;
    vector<int>dis;

void bfs(int node)
{
    queue<int>q;
    // q.push(node);
    visited[node] = 1;
    dis[node]=0; // distance of the starting node is 0
    q.push(node); //first mark the node aas visited the push the node in the queue
    while(!q.empty())
    {
        int curr = q.front(); //current node is the front element of the queue
        q.pop(); //pop is done to remove the current node from the queue , so that we can move to the next node
        // now we will traverse the neighbours of the current node , becasue we take one node traverse it neighbours and then move to the next node
        for(auto v:g[curr]) //v is the neighbour of the current node
        {
            if(!visited[v])
            {
                visited[v] = 1;
                dis[v] = dis[curr] + 1; // distance of the neighbour is the distance of the current node + 1
                q.push(v);  // if the neighbour is not visited then mark it as visited and push it in the queue
            }
        
    }
}
 int main () {
    cin >> n >> m;//n is the number of nodes and m is the number of edges
    g.resize(n+1); // very important to resize the graph
    for(int i = 0; i < m; i++) {
        int a,b;
        cin >> a >> b;
        g[a].push_back(b);
        // if undirected graph then uncomment this
        g[b].push_back(a);
    }
    visited.assign(n+1,0);
    dis.assign(n+1,1e9); // distance of all the nodes is initialized to infinity
   bfs(1); // call the bfs for the starting node and the bfs will traverse the whole graph
  
    
    return 0;
}
