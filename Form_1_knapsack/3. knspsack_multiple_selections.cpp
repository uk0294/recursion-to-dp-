// 0-infinte knapsack , - take multiple item multiple no.of times
// time complexity calculation = (no. of states)(1+no. of transitions)
//                                   (N*W)(1+max(x/w[i]))=(N*W)(W)=N*W^2

#include <bits/stdc++.h>
using namespace std;
int n;
int w[3003]; // weight
int v[3003]; // values
int W;
int dp[3003][3003];
int rec(int i, int x)
{
    // pruning
    // basecase
    if (i == n)
    {
        return 0;
    }
    // cache chek
    if (dp[i][x] != -1)
    {
        return dp[i][x];
    }
    // transition
    int ans = rec(i + 1, x); // donot take
    if (w[i] <= x)
    {
        // take
        // if we do the belo then TC=N*W
        int ans = rec(i + 1, x);
        if (w[i] <= x)
        {
            ans = max(ans, rec(i, x - w[i]) + v[i]); // just small change instead of i+1 we are at i
        }

        // the below TC is N*W^2
        // int ans = 0;
        // for (int nt = 0; nt <= x / w[i]; nt++)
        // w
        //     ans = max(ans, rec(i + 1, x - nt * w[i]) + nt * v[i]);
        // }
    }
    // save and return
    dp[i][x] = ans;
    return ans;
}

void solve()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> w[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    cin >> W;
    memset(dp, -1, sizeof(dp));

    cout << rec(0, W);
}
int main()
{
    solve() return 0;
}