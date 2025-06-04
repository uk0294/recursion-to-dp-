#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>dp;
string s1,s2;
int n,m;
vector<vector<int>>back;

int rec(int i, int j)
{
    // in base case no and condition because any one of the s1 , s2 can end , so can give issues 
   if(i >= n || j >= m) return 0;   // here in the base case did not do equal to because in that case we needed to add additioal check in transition which is i+1>=n
   if(dp[i][j] != -1) return dp[i][j];
   int ans = 0;
   
   if(s1[i] == s2[j])
   {
       int temp = 1 + rec(i+1, j+1);  
       if(temp > ans)
       {
           ans = temp;
           back[i][j] = 0; // diagonal move (match)
       }
   }

   int temp1 = rec(i+1, j);  // skip s1[i]
   if(temp1 > ans)
   {
       ans = temp1;
       back[i][j] = 1;
   }

   int temp2 = rec(i, j+1);  // skip s2[j]
   if(temp2 > ans)
   {
       ans = temp2;
       back[i][j] = 2;
   }

   return dp[i][j] = ans;
}

void generate(int i, int j)
{
    if(i == n || j == m) return;    // here in base case we use equal to because we are terminating , here no return type as it is void
    
    int index = back[i][j];
    // very important note , here we use if - else , becaus we wnat to go once as we are back tracking
    // in rec we want to go multiple times so if statements only no else statement
    if(index == 0)  // match found
    {
        cout << s1[i];  // print the character
        generate(i+1, j+1);
    }
    else if(index == 1)  // skip s1[i]
    {
        generate(i+1, j);
    }
    else if(index == 2)  // skip s2[j]
    {
        generate(i, j+1);
    }
}

int main()
{
    cin >> s1 >> s2;
    n = s1.size();
    m = s2.size();
    dp.assign(n, vector<int>(m, -1));
    back.assign(n, vector<int>(m, -1));
    
    cout << "LCS Length: " << rec(0, 0) << endl;
    cout << "LCS: ";
    generate(0, 0);
    cout << endl;

    return 0;
}