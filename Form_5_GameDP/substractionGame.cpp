#include<bits/stdc++.h>
using namespace std;
int n;
int dp[3003];
int rec(int x)
{
  // pruning 
  // basecase
  if(x==0)
{
    return 0;

}
  //cache chek 
   if(dp[x]!=-1)
   {
    return dp[i][x];
   }
  //transition
  int ans=0; 
  //loop through all powers of 2
  for(int i=0;1<<m;i++)
  {
    if(rec(x-(1<<i))==0)  // if any of the state is losing then i am winning 
    {
        ans=1;
        break;
    }
  }

  return dp[x]=ans;
}


void solve ()
{
    cin >>n;


    cout<<rec(n);

    // by pattterb
    if(n%3==0) cout <<"win"<<endl;
    else cout<<"lose"<<endl;
}
int main()
{
   solve()
    return 0 ;
}