// Write your code here
#include<bits/stdc++.h>
using namespace std;
int n;
vector<int>arr;
int dp[500][500];
int x[101],y[101];  // x and y stores the size of matrix like n*m - x - row , y - column
int back[101][101];

int rec(int l ,int r)  // minmum cost of meging from l to r
{
   
   if(l>r) return 0;
   if(l==r)    
    return 0;

    if(dp[l][r]!=-1) return dp[l][r];

int ans=1e9;
   // l+1 to r-1
    for(int mid=l;mid<r;mid++)
    {
         
        int cost=x[l]*y[mid]*y[r];
        if(rec(l,mid)+rec(mid+1,r)+cost<ans)
          {
            ans=rec(l,mid)+rec(mid+1,r)+cost;
            back[l][r]=mid;
          }
            
         
    }


    return dp[l][r]=ans;
}

int opb[101];
int cb[101];
void generate(int l , int r)
{
    if(l==r) return ;
    opb[l]++;
    cb[r]++;
    int mid=back[l][r];
    generate(l,mid);
    generate(mid+1,r);
}
void solve()
{
cin>>n;
x.resize(n+1);
y.resize(n+1);
memset(dp,-1,sizeof(dp));
for(int i=1;i<=n;i++)
{
    cin>>x[i]>>y[i];
}

cout<<rec(1,n)<<endl;
generate(1,n);
for(int i=1;i<=n;i++)
{
    for(int x=0;x<opb[i];x++)
    {
        cout<<"("<<" ";
    }
    cout<<i<<" ";

    for(int x=0;x<cb;x++)
    {
        cout<<")"
    }
}


}
int main()
{


solve();


    return 0;
}