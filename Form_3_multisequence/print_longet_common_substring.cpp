#include<bits/stdc++.h>
using namespace std;

string s1, s2;
int n, m;
vector<vector<int>> dp;

// for printing the longest common substring , we maintain where did the last charactrer end for the common part
// for s1 it ended at ending_i , for s2 ,ended at ending-j
// now we got the ending position , now we can get the stating position by , the substracting from the max_length of the longest common substring
//we got the stating posion so now just print from start to end that's it that's the logic 
void generate(int end_i, int end_j, int length)
{
    // Print the substring from the ending position backwards
    for(int k = length - 1; k >= 0; k--)
    {
        cout << s1[end_i - k];
    }
}

int main()
{
    cin >> s1 >> s2;
    n = s1.size();
    m = s2.size();
    
    // Initialize DP table with size (n+1) x (m+1)
    dp.assign(n + 1, vector<int>(m + 1, 0));
    
    int maxLength = 0;
    int ending_i = 0, ending_j = 0;  //maintain this for the printinf 
    
    // Fill the DP table
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(s1[i-1] == s2[j-1])  // Characters match
            {
                dp[i][j] = 1 + dp[i-1][j-1];
                
                // Update maximum length and ending position
                if(dp[i][j] > maxLength)
                {
                    maxLength = dp[i][j];
                    ending_i = i - 1;  // Convert to 0-based indexing 
                    ending_j = j - 1;
                }
            }
            else
            {
                dp[i][j] = 0;  // Reset to 0 for substring
            }
        }
    }
    
    cout << "LCS Length: " << maxLength << endl;
    
    if(maxLength > 0)
    {
        cout << "LCS: ";
        generate(ending_i, ending_j, maxLength);
        cout << endl;
    }
    else
    {
        cout << "No common substring found" << endl;
    }
    
    return 0;
}