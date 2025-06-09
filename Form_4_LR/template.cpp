// Write your code here
#include<bits/stdc++.h>
using namespace std;
int n;
vector<int>arr;
int dp[500][500];
int prefix[500];


int get_sum(int l , int r)
{
    if(l==0) return prefix[r];
    else return prefix[r]-prefix[l-1];

    // this will give tle   always use prefix sum 
//    int sum=0;
//     for(int i=l;i<=r;i++)
//       sum+=arr[i];

//       return sum;
}

int rec(int l ,int r)  // minmum cost of meging from l to r
{
   // thought process , during the last step the mergin will contain two elements 
   // let's say mergin happens between l,mid, ans mid+1 to r 
   // then cost = product of the two elements- elemts obtained by howw by summing up the eleemens from l to mid % 100 and similaar for mid+1 to r and do it for all mid

   if(l==r)     // for two element if l==rthen return 0 , donot do l+1=r 
    return 0;

    if(dp[l][r]!=-1) return dp[l][r];

int ans=1e9;
   // l+1 to r-1
    for(int mid=l;mid<r;mid++)
    {
         
        int cost=(get_sum(l,mid)%100)*(get_sum(mid+1,r)%100);
              ans=min(ans,rec(l,mid)+rec(mid+1,r)+cost);
         
    }


    return dp[l][r]=ans;
}
void solve()
{
cin>>n;
arr.resize(n);
memset(dp,-1,sizeof(dp));
for(int i=0;i<n;i++)
{
    cin>>arr[i];
}

prefix[0]=arr[0];
for(int i=1;i<n;i++)
{
    prefix[i]=prefix[i-1]+arr[i];
}
cout<<rec(0,n-1)<<endl;
}
int main()
{


solve();


    return 0;
}