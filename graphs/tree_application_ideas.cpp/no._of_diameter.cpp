#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>g;
vector<int>dep;
vector<int>par;
int n;
int d;

void dfs(int node, int parent, int depth)
{
    dep[node] = depth;
    par[node] = parent;
    for(auto v : g[node])
    {
        if(v != parent)
        {
            dfs(v, node, depth + 1);
        }
    }
}

// Count nodes at distance d/2 using DFS
long long countNodesAtDistanceDFS(int node, int parent, int curr_depth)
{
    if(curr_depth == d/2)
    {
        return 1;
    }
    
    if(curr_depth > d/2)
    {
        return 0;
    }
    
    long long count = 0;
    for(int child : g[node])
    {
        if(child != parent)
        {
            count += countNodesAtDistanceDFS(child, node, curr_depth + 1);
        }
    }
    
    return count;
}

void solve()
{
    cin >> n;
    g.resize(n + 1);
    dep.assign(n + 1, 0);
    par.assign(n + 1, 0);
    
    for(int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    // Find one end of diameter
    dfs(1, 0, 0);
    int max1 = 1;
    for(int i = 2; i <= n; i++)
    {
        if(dep[i] > dep[max1])
        {
            max1 = i;
        }
    }

    // Find other end of diameter
    dfs(max1, 0, 0);
    int max2 = 1;
    for(int i = 2; i <= n; i++)
    {
        if(dep[i] > dep[max2])
        {
            max2 = i;
        }
    }
    
    d = dep[max2];
    
    long long total_diameters = 0;
    
    if(d % 2 == 0)
    {
        // One center case
        int center = max2;
        for(int i = 0; i < d/2; i++)
        {
            center = par[center];
        }
        
        // Count nodes at distance d/2 from center in each subtree
        vector<long long> subtree_counts;
        
        for(int child : g[center])
        {
            long long count = countNodesAtDistanceDFS(child, center, 1);
            if(count > 0)
            {
                subtree_counts.push_back(count);
            }
        }
        
        // Calculate pairs from different subtrees
        for(int i = 0; i < subtree_counts.size(); i++)
        {
            for(int j = i + 1; j < subtree_counts.size(); j++)
            {
                total_diameters += subtree_counts[i] * subtree_counts[j];
            }
        }
    }
    else
    {
        // Two centers case
        int c1 = max2;
        for(int i = 0; i < d/2; i++)
        {
            c1 = par[c1];
        }
        int c2 = par[c1];
        
        // Count nodes at distance d/2 from each center
        long long n1 = countNodesAtDistanceDFS(c1, c2, 0);
        long long n2 = countNodesAtDistanceDFS(c2, c1, 0);
        
        total_diameters = n1 * n2;
    }
    
    cout << total_diameters << endl;
}

int main()
{
    solve();
    return 0;
}