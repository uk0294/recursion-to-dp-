include<bits/stdc++.h>
using namespace std;

    int n,m ;
    vector<vector<int>>g;
    vector<int>indeg;
     vector<int>topo;

void kahn()
{
    queue<int>q;
    for(int i=1;i<=n;i++)
    {
        if(indeg[i]==0)
         q.push(i);
    }
    while(!q.empty())
    {
        int curr = q.front(); //current node is the front element of the queue
        q.pop(); //pop is done to remove the current node from the queue , so that we can move to the next node
        // now we will traverse the neighbours of the current node , becasue we take one node traverse it neighbours and then move to the next node
        topo.push_back(curr);
        for(auto v:g[curr]) //v is the neighbour of the current node
        {
           indeg[v]-- ; // jo node abhi visit horha hai uska indeg ko ghata do 
           if(indeg[v]==0)
            q.push(v);
        
    }
}
 int main () {
    cin >> n >> m;//n is the number of nodes and m is the number of edges
    g.resize(n+1); // very important to resize the graph
    indeg.assign(n+1,0);
    for(int i = 0; i < m; i++) {
        int a,b;
        cin >> a >> b;
        g[a].push_back(b);
        indeg[b]++;
    }
   kahn();
   // we can detect the cycle also
   if(topo.size()!=n)
   {
    cout<<"cycle exsist"<<endl;
   }

   else
   {
   for(auto v:topo)
   {
    cout<<v<<" ";
   }
   }

   // how do we print the lexographical smallest topological ordering 
   // we use priority queue
  
    
    return 0;
}
