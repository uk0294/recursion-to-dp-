// https://atcoder.jp/contests/dp/tasks/dp_c

#include <bits/stdc++.h>
using namespace std;

int n;
long long dp[100005][4]; // We use 4 columns: index 0 for last activity A, 1 for B, 2 for C, and index 3 for "no previous activity".
long long A[100005], B[100005], C[100005];

// last is the index of the activity chosen on the previous day.
// We use -1 (which maps to index 3 in dp) to denote that no activity was chosen before day 0.
long long rec(int day, int last) {
    if(day == n)
        return 0;
    
    // Map last = -1 to index 3 in dp, otherwise use last itself.
    int idx = (last == -1 ? 3 : last);
    if(dp[day][idx] != -1)
        return dp[day][idx];
    
    long long ans = 0;
    // Try choosing activity A if it wasn’t done the previous day.
    if(last != 0)
        ans = max(ans, rec(day + 1, 0) + A[day]);
    // Try choosing activity B if it wasn’t done the previous day.
    if(last != 1)
        ans = max(ans, rec(day + 1, 1) + B[day]);
    // Try choosing activity C if it wasn’t done the previous day.
    if(last != 2)
        ans = max(ans, rec(day + 1, 2) + C[day]);
    
    dp[day][idx] = ans;
    return ans;
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> A[i] >> B[i] >> C[i];
    }
    memset(dp, -1, sizeof(dp));
    cout << rec(0, -1) << endl;
}

int main() {
    solve();
    return 0;
}
