#include <bits/stdc++.h>
using namespace std;
int n;
int arr[10001];
int dp[10001];

// TC = no. of states * transistion  = N* N = N^2

int rec(int level) // returns the best LIS ending at level
{
    // pruning
    if (level < 0)
        return 0;

    // base case

    // cache
    if (dp[level] != -1)
    {
        return dp[level];
    }
    // compute
    int ans = 1;
    for (int prev_taken = 0; prev_taken < level; prev_taken++)
    {
        if (arr[prev_taken] < arr[level])
        {
            ans = max(ans, 1 + rec(prev_taken));
        }
    }
    // save and rreturn
    return dp[level] = ans;
}
void solve()
{
    memset(dp, -1, sizeof(dp));
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int best = 0;
    for (int i = 0; i < n; i++)
    {
        best = max(best, rec(i))
    }

    cout << best
}
int main()
{

    return 0;
}