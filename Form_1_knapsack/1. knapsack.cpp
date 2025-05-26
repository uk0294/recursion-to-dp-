//// below is code of knapsack without DP and it's complexity is 2^N, we need to reduce it to 2N by defining the chaching

// #include<bits/stdc++.h>
// using namespace std;
// int n;
// int w[3003]; // weight 
// int v[3003];//values
// int W;
// int rec(int i,int x)
// {
//   // pruning 
//   // basecase
//   if(i==n)
// {
//     return 0;

// }
//   //cache chek 
//   //transition
//   int ans=rec(i+1,x); // donot take 
//   if(w[i]<=x)
//   {
//     ans=max(ans,rec(i+1,x-w[i])+v[i]) ;  // take 
//   }
//   //save and return 
//   return ans;
// }


// void solve ()
// {
//     cin >>n;
//     for (int i=0;i<n;i++)
//     {
//         cin>>w[i];
//     }

//     for (int i=0;i<n;i++)
//     {
//         cin>>v[i];
//     }
//     cin>>W;

//     cout<<rec(0,W);

// }
// int main()
// {
//    solve()
//     return 0 ;
// }

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//using the dp 

#include<bits/stdc++.h>
using namespace std;
int n;
int w[3003]; // weight 
int v[3003];//values
int W;
int dp[3003][3003];
int rec(int i,int x)
{
  // pruning 
  // basecase
  if(i==n)
{
    return 0;

}
  //cache chek 
   if(dp[i][x]!=-1)
   {
    return dp[i][x];
   }
  //transition
  int ans=rec(i+1,x); // donot take 
  if(w[i]<=x)
  {
    ans=max(ans,rec(i+1,x-w[i])+v[i]) ;  // take 
  }
  //save and return 
  dp[i][x]=ans;
  return ans;
}


void solve ()
{
    cin >>n;
    for (int i=0;i<n;i++)
    {
        cin>>w[i];
    }

    for (int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    cin>>W;
    memset(dp,-1,sizeof(dp));

    cout<<rec(0,W);

}
int main()
{
   solve()
    return 0 ;
}