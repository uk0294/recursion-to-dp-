#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
int n, m;
vector<vector<int >>g;
vector<int>indeg, dp;

void kahn()
{ 
    queue<int >q;
    dp[1] = 1; // number of ways to reach node 1 is 1
    for(int i=1;i<=n;i++)
    {
        if(indeg[i]==0)
        {
            q.push(i);
        }
    }

    while(!q.empty())
    {
        int curr=q.front();
        q.pop();
        for(auto v:g[curr])
        {
            indeg[v]--;
            if(indeg[v]==0)
            { 
                q.push(v);
            }
            dp[v] = (dp[v] + dp[curr]) % mod; // update dp[v]
        }
    }
}

int main()
{
    cin>>n>>m;
    g.resize(n+1);
    indeg.assign(n+1,0);
    dp.assign(n+1,0);
    for(int i=0;i<m;i++)
    {
        int a, b;
        cin>>a>>b;
        g[a].push_back(b);
        indeg[b]++;
    }
    kahn();
    cout<<dp[n]<<endl; // print the number of ways to reach node n

    return 0;
}
