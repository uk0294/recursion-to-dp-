/// q is of the at coder , minimise the cost of travelling from step 1 to N

#include <bits/stdc++.h>
using namespace std;
#define long long int;
int n, k;
int arr[1001];
int dp[10001];

int rec(int level)
{
    // pruning
  
    // basecase
    if(level==0)
    {
        return 0;
    }

    // cache check
     if(dp[level]!=-1)
     {
        return dp[level];
     }
    // transition
    int ans = 1e9;
    for (int i = 1; i <= k; i++)
    {
        if (level -i >=0)
        {
            ans = min(ans, rec(level- i) + arr[level - i] - arr[level]);
        }

        else{
            break;
        }
    }

    dp[level]=ans;

    return ans;
}

void solve()
{
    cin >> n >> k;
    memset(dp,-1,sizeof(dp));
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << rec(n - 1) << "\n";
}
int main()
{
    solve();
    return 0;
}