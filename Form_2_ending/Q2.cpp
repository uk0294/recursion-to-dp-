// maximum sum path from 1,1 to n,m

#include <bits/stdc++.h>
using namespace std;
int n, m;
int arr[10001][10001];
int dp[10001][10001];
const int INF = 1e9;
bool done[10001][10001];
int rec(int r, int c) // returns the maximum sum of the path
{
    // pruning
    if (r < 0 || c < 0)
        return -INF;

    // base case
    // we are starting from the firsr so we will get that first value
    if (r == 0 && c == 0)
    {
        return arr[0][0];
    }
    // cache
    // if (dp[r][c]!= -1)
    // {
    //     return dp[r][c];
    // }
    if (done[r][c])
    {
        return dp[r][c];
    }

    // compute
    int ans = -INF; // for maximisig problem we start with -INF
    if (c != 0)
    {
        ans = max(ans, rec(r, c - 1) + arr[r][c]);
    }

    if (r != 0)
    {
        ans = max(ans, rec(r - 1, c) + arr[r][c]);
    }
    // save and rreturn
    done[r][c] = 1;
    return dp[r][c] = ans; // probem with the dp is that some of the entry in matrix can be negative and can be -1 so in the chache check it will run fot=r infinite times when -1 comes
}
void solve()
{
    memset(dp, -1, sizeof(dp));
    cin >> n >> m for (int j = 0; j < m; j++)
    {
        cin >> arr[i][j];
        done[i][j] = 0;
    }
    cout << rec(n - 1, m - 1);
    cout << endl;
}
int main()
{

    return 0;
}