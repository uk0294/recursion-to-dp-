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
        ans = max(ans, rec(i + 1, x - w[i]) + v[i]); // take
    }
    // save and return
    dp[i][x] = ans;
    return ans;
}

vector<int> solution;
// for prinnting the solution we actually define the generate function
void generate(int i, int x)
{
    if (i == n)
    {
        return;
    }

    else
    {
        // don't take
        int donttake = rec(i + 1, x);
        if (w[i] <= x)
        {
            // can possibly take
            int take = rec(i + 1, x - w[i]);

            if (donttake > take)
            {
                generate(i + 1, x);
            }
            else
            {
                solution.push_back(i);
                generate(i + 1, x - w[i]);
            }
        }

        else
        {
            // don't take
            generate(i + 1, x);
        }
    }
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

    cout << rec(0, W) << endl;
    generate(0, W);
    cout << solution.size();
    for (auto v : solution)
    {
        cout << v << " ";
    }
}
int main()
{
    solve() return 0;
}