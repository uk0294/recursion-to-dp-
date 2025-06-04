#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    
    int n = s1.size();
    int m = s2.size();
    
// no need for this as we are assigning to 0;
    //    for(int i=0;i<n;i++)
    //   dp[i][0]=0;
    // for(int j=0;j<m;j++)
    //   dp[0][j]=0;
    
    // Initialize DP table with size (n+1) x (m+1), all values = 0
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    
    int maxLength = 0;
    
    // Fill the DP table
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(s1[i-1] == s2[j-1])  // Characters match
            {
                dp[i][j] = 1 + dp[i-1][j-1];
                maxLength = max(maxLength, dp[i][j]);
            }
            else
            {
                dp[i][j] = 0;  // Reset to 0 for substring
            }
        }
    }
    
    cout << "Longest Common Substring Length: " << maxLength << endl;
    
    return 0;
}