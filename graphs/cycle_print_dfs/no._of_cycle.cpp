#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>g;
vector<int>col;
vector<int>parent;
vector<int>any_cycle ; // there are lot of cycles possible but we will just print 1 as printing all will exceed the linear tc 
bool is_cycle=false;
vector<int>cnt_cycle;
vector<int>prefix_order;

int n , m ;

void dfs(int node,int par)
{
    col[node]=2;
    parent[node]=par; // node ka parent is par
    for(auto v : g[node])
    {
        if(col[v]==1)
        {
            //forward edge 
           dfs(v,node); // because node is the parent of v 
        }
        else if(col[v]=2)
        {
            //back edge so we have a cycle 
            // backedge from node to the v . because node is the current and we are exploring v , whihc is already visited so it is marked 2 
            is_cycle=true;
            //  for printing note we stored the parent of each v in the parent vector
            // so we will backtrack 
            int temp=node; // starting from the node which is the end ;
            while (temp!=v) // we have a cycle from node to v, so until we reach v keep pushing the elements
            {
                any_cycle.push_back(temp);
                temp=parent[temp]; // we trach the parent of temp 
            }
            // at last we ignored the pushing of v so push the v itself 
            any_cycle.push_back(v);
            reverse(any_cycle.begin
            (),any_cycle.end());  // reversed because we had back tracked , so just make it forward


            // counting the no. of cycles
            //for every backedge that we find the cnt cycle
            cnt_cycle[node]++;
            cnt_cycle[parent[v]]--; 
        }
        else if(col[v]==3)
        {
            //cross edge and is not imp 
        }
    }
    col[node]=3;
    prefix_order.push_back(node);
}
int main ()
{
    cin>>n>>m;
    g.resize(n+1);
    col.assign(n+1,1);//initially all colour as 1
    parent.assgn(n+1,0); // initially no parent 
    cnt_cycle.assign(n+1,0);

    for(int i=0;i<m;i++)
    {
        int a , b;
        cin>>a>>b;
        g[a].push_back(b);
       
    }

    for(int i=1;i<=n;i++)  //running dfs on every node 
    {
        if(col[i]==1)
        dfs(i,0);
    }
    

    // printing the cycle
    for(auto v:any_cycle)
    {
        cout<<v<<"->";
    }
    cout<<endl;

    //printing the no. of cycle 
    for(v:prefix_order)
    {
        cnt_cycle[parent[v]]+=cnt_cycle[v]; /// we add the parent of v to the the v 
    }
    int cnt_node=0;
    for(int i=0;i<n;i++)
    {
        if(cnt_cycle[i]>0)cnt_node++; 
    }
    cout<<cnt_node<<endl;
    return 0;
}