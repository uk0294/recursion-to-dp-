#include <bits/stdc++.h>
using namespace std;
#define long long int;
int n;
int k int arr[10001];
int dp[10001][1001];

// TC = no. of states * transistion  = N* N = N^2
// i is the element level , and x is the no. of sub arrays required
int rec(int i, int x) // returns the min of minimum sum in the k sub arrays
{
    // pruning
    if (i < 0)
    {
        return 0;
    }

    // base case
    if (i == -1) // the last elemenmt of the array
    {
        if (x == 0)
        {
            return 0;
        }
        else
        { // invslid , we are using the 1e9 as in this case we need to minimize the minimum sum of the elements of thesubarrays
            return 1e9;
        }
    }
    // cache
    if (dp[i][x] != -1)
    {
        return dp[i][x];
    }
    // compute
    int ans = 1e9;
    int min_seen = arr[i];
    for (int j = i - 1; j >= -1; j--)
    {
        // ans=min(ans,rec(j,x-1)+min(arr[j-1......i]))//we should maintain the running minimum
        ans = min(ans, rec(j, x - 1) + min_seen);
        min_seen = arr[j]; // always maintain the running minimum
    }
    // save and rreturn
    return dp[i][x] = ans;
}
void solve()
{
    memset(dp, -1, sizeof(dp));
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << rec(n - 1, k) << endl;
    ;
}
int main()
{

    return 0;
}