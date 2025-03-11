// in this type of problem with additional constriants think what extrat paarmeter needs to be added to the state to make the constriant work

// for example you can take max k items
#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int n;
int w[3003]; // weight
int v[3003]; // values
int W;
int k;
int dp[3003][3003][100];
int rec(int i, int x, int items_left)
{
    // pruning
    // basecase
    if (i == n)
    {
        return 0;
    }
    // cache chek
    if (dp[i][x][items_left] != -1)
    {
        return dp[i][x][items_left];
    }
    // transition
    int ans = rec(i + 1, x, items_left); // donot take
    if (w[i] <= x && items_left > 0)
    {
        ans = max(ans, rec(i + 1, x - w[i], items_left - 1) + v[i]); // take
    }
    // save and return
    dp[i][x][items_left] = ans;
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
    cin >> k;
    memset(dp, -1, sizeof(dp));

    cout << rec(0, W, k);
}
int main()
{
    solve() return 0;
}

////// another variation max k items+ sum of the weights taken should be divisible by m for items taken //////

// in this type of problem with additional constriants think what extrat paarmeter needs to be added to the state to make the constriant work

#include <bits/stdc++.h>
using namespace std;
int n;
int w[3003]; // weight
int v[3003]; // values
int W;
int k;
int m;
int dp[3003][3003][100];
int rec(int i, int x, int items_left)
{
    // pruning
    // basecase
    if (i == n)
    {
        sum_of_items = W - x; // W is total , x hai jo bacha hua hai
        if (sum_of_items % m == 0)
        {
            return 0; // valid
        }
        else
        {
            // invalid
            // penalty of -INF
            return -INF;
        }
    }
    // cache chek
    if (dp[i][x][items_left] != -1)
    {
        return dp[i][x][items_left];
    }
    // transition

    int ans = rec(i + 1, x, items_left); // donot take
    if (w[i] <= x && items_left > 0)
    {
        sum = 0;
        ans = max(ans, rec(i + 1, x - w[i], items_left - 1) + v[i]); // take
    }
    // save and return
    dp[i][x][items_left] = ans;
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
    cin >> k;
    cin >> m;
    memset(dp, -1, sizeof(dp));

    cout << rec(0, W, k);
}
int main()
{
    solve() return 0;
}
