#include<bits/stdc++.h>
using namespace std;

#define int long long
int t,n;
vector<int>c;
vector<string>v;
int dp[100001][2];

string reversed(string s)  // Changed: return string instead of void
{
    reverse(s.begin(),s.end());
    return s;  // Added return statement
}

int rec(int i , int j)  // should i reverse the i-th string
{
    //base case 
    if(i == n) return 0;  // Changed: proper base case when we've processed all strings
    if(dp[i][j]!=-1) return dp[i][j];
 
    //transitions 
    int ans=1e18;
    
    // For first string (i == 0), we can choose to reverse or not
    if(i == 0)
    {   
        ans = min(ans, rec(i+1, 0));  // Don't reverse current string
        ans = min(ans, c[i] + rec(i+1, 1));  // Reverse current string
    }
    else  // For subsequent strings, check if ordering is maintained
    {
        // Previous string was not reversed (j == 0 means current should not be reversed)
        if(j == 0)
        {
            // Try not reversing current string
            if(v[i-1] <= v[i])
                ans = min(ans, rec(i+1, 0));
            // Try reversing current string  
            if(v[i-1] <= reversed(v[i]))
                ans = min(ans, c[i] + rec(i+1, 1));
        }
        // Previous string was reversed (j == 1 means current should be reversed)
        else if(j == 1)
        {
            // Try not reversing current string
            if(reversed(v[i-1]) <= v[i])
                ans = min(ans, rec(i+1, 0));
            // Try reversing current string
            if(reversed(v[i-1]) <= reversed(v[i]))
                ans = min(ans, c[i] + rec(i+1, 1));
        }
    }
    
    return dp[i][j] = ans;
}

void solve()
{
   cin >> n;
   v.clear();
   c.clear();
   v.resize(n);
   c.resize(n);
   memset(dp, -1, sizeof(dp));
   
   for(int i = 0; i < n; i++)
   {
       cin >> c[i];
   }
   
   for(int i = 0; i < n; i++)  // Fixed: removed double push_back
   {
       cin >> v[i];  // Direct assignment instead of push_back after resize
   }

   int result = rec(0, 0);  // Start with first string, not reversed initially
   if(result >= 1e18) result = -1;  // Check for impossibility
   cout << result << endl;
}

signed main()
{
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}