// importat this can be template for similar problems like 
/*This pattern works for:

Word Break
Coin Change (can we make amount X?)
Jump Game (can we reach end?)
Palindrome Partitioning (can we partition into palindromes?)

*/

/*
The Pattern to Remember 🧠
For ANY "can we break/segment" problem:

1. dp[i] = "can we achieve our goal up to position i?"
2. Base case = dp[0] = true (empty/start is always achievable)
3. Transition = dp[i] = true if there exists some j < i where:

dp[j] = true (we can reach j)
AND condition from j to i is satisfied (word exists in dictionary)



Template:
cppdp[0] = true;
for(int i = 1; i <= n; i++) {
    for(int j = 0; j < i; j++) {
        if(dp[j] && condition_check(j, i)) {
            dp[i] = true;
            break;
        }
    }
}
*/




#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        string s;
        cin >> n >> s;
        
        // Read dictionary words into unordered_map for O(1) lookup
        unordered_map<string, bool> dictionary;
        for(int i = 0; i < n; i++)
        {
            string word;
            cin >> word;
            dictionary[word] = true;
        }
        
        int len = s.size();
        
        // dp[i] = true means we can form valid words from start to position i
        vector<bool> dp(len + 1, false);
        dp[0] = true; // Empty string is always valid (base case)
        
        // For each position in string
        for(int i = 1; i <= len; i++)
        {
            // Look back at most 20 positions (max word length constraint)
            for(int j = 1; j <= 20 && j <= i; j++)
            {
                // If position (i-j) was valid AND substring from (i-j) to i exists in dictionary
                if(dp[i-j] && dictionary.find(s.substr(i-j, j)) != dictionary.end())
                {
                    dp[i] = true;
                    break; // Found one valid way, no need to check further
                }
            }
        }
        
        // Check if entire string can be segmented
        if(dp[len])
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}