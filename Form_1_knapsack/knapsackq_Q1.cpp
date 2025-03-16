#include <bits/stdc++.h>
using namespace std;

long long int n;
long long int W;
long long int dp[100][100];
long long int final;

long long int w[100],v[100];

long long int rec(int lvl, int take)
{
    // pruning

    // basecase
    if (lvl == n)
    {
        return 0;
    }

    // cache
    if (dp[lvl][take] != -1)
    {
        return dp[lvl][take];
    }
    // transition

    // donot take
    long long int ans = 0;
    ans = rec(lvl + 1, take);
    // take
    if (w[lvl] <= take)
    {
        ans = max(ans, rec(lvl + 1, take - w[lvl]) + v[lvl]);
    }
    // save and return
    dp[lvl][take] = ans;
    return ans;
}

void solve()
{
    cin >> n >> W;
    for (int i = 0; i < n; i++)
    {
        cin >> w[i] >> v[i];
    }
    memset(dp, -1, sizeof(dp));

    final = rec(0, W);
    cout << final << endl;
}

int main()
{
    solve();

    return 0;
}