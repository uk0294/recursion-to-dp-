// my previous recursive solution

// // Write your code here
// #include<bits/stdc++.h>
// using namespace std;

// int n;
// int dp[1000000][4];
// //0100
// // last =0 means no match so take 0 or 1 at thispoint
// int rec(int i,int last)
// {
//     if(i==n) 
//       return 1;


      
//     if(last==0)
//     {
//        return dp[i][last]=rec(i+1,1)+rec(i+1,0);

//     }

//     else if(last==1)
//     {
//        return dp[i][last]=rec(i+1,1)+rec(i+1,2);
       
//     }


//     else if(last==2)
//     {
//        return dp[i][last]=rec(i+1,3)+rec(i+1,0);
       
//     }

//     else if(last==3)
//     {

//         // cant take 0 we are at 010  will take 1 become 0101  lat =2
//         return dp[i][last]=rec(i+1,2);

//     }
// }
// void solve()
// {
//    cin>>n;
//    memset(dp,-1,sizeof(dp));
//    cout<<rec(0,0);


// }
// int main()
// {
//   int t ;
//   cin>>t;
//   while(t--)
//    {

//     solve();
//    }


//     return 0;
// }

#################################################################################################################

#include<bits/stdc++.h>
using namespace std;

#define int long long 
const int mods = 1000000007;
const int MAXN = 1000001; // computing for all N

int dp[MAXN]; // dp[i] = answer for length i
bool computed = false;  

void precompute() {
    if(computed) return;
    
    // We'll use bottom-up DP
    // dp_state[i][j] = number of ways to fill first i positions with last state j
    vector<vector<int>> dp_state(MAXN, vector<int>(4, 0));  // dp_stae[10001][4]
    
    // Base case: first position can start with any valid state
    dp_state[1][0] = 1;  // Can start with state 0
    dp_state[1][1] = 1;  // Can start with state 1
    dp_state[1][2] = 0;  // Cannot start with state 2 (would need previous state)
    dp_state[1][3] = 0;  // Cannot start with state 3 (would need previous state)
    
    // Fill the DP table
    for(int i = 2; i < MAXN; i++) {
        // Based on your transition rules:
        // if last == 0: can go to state 0 or 1
        // if last == 1: can go to state 1 or 2  
        // if last == 2: can go to state 0 or 3
        // if last == 3: can go to state 2
        
        // To reach state 0 at position i, previous state must be 0 or 2
        dp_state[i][0] = (dp_state[i-1][0] + dp_state[i-1][2]) % mods;
        
        // To reach state 1 at position i, previous state must be 0 or 1
        dp_state[i][1] = (dp_state[i-1][0] + dp_state[i-1][1]) % mods;
        
        // To reach state 2 at position i, previous state must be 1 or 3
        dp_state[i][2] = (dp_state[i-1][1] + dp_state[i-1][3]) % mods;
        
        // To reach state 3 at position i, previous state must be 2
        dp_state[i][3] = dp_state[i-1][2] % mods;
    }
    
    // For each length, sum all possible ending states
    for(int i = 1; i < MAXN; i++) {
        dp[i] = (dp_state[i][0] + dp_state[i][1] + dp_state[i][2] + dp_state[i][3]) % mods;
    }
    
    computed = true;
}

void solve() {
    int n;
    cin >> n;
    cout << dp[n] << "\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    precompute(); // Precompute all answers once
    
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}