#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
string s1,s2;
int n, m;
int dp[500][500];
int rec(int i, int j)
{
    //base case 
    if(j<0) return i+1; // we are done with the check  // still left with some index which is i+1
    if(i<0) return j+1;
    if(i<0&&j<0) return 0;
    //cache check
    if(dp[i][j]!=-1) return dp[i][j];

    //transitions
    int ans=INF;
    if(s1[i]==s2[j])
     ans=min(ans,rec(i-1,j-1));
    //  if(i-1>=0&&j-1>=0)  // this is not the requirement , because think of a case where i is over but j is still left so in that cas this statemnet will not execute and thus the rec call will not execute and thus the base case for it which is i+1, will not get executed , that;s why avoiding this
      ans=min(ans,1+rec(i-1,j-1));
    if(i-1>=0) 
    ans=min(ans,1+rec(i-1,j));
    if(j-1>=0)
     ans=min(ans,1+rec(i,j-1));

     return dp[i][j]=ans;
     
 }
int main()
{
   cin>>s1>>s2;
   n=s1.size();
   m=s2.size();
   memset(dp,-1,sizeof(dp));
   cout<<rec(n-1,m-1);


    return 0;
}