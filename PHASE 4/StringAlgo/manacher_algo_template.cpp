// Write your code here  // finding the longest pallindrome
#include<bits/stdc++.h>
using namespace std;
  vector<int>p;
struct manacher{
  

  void run_manacher(string s)
  {
    int n=s.length();
    p.assign(n,1);  //initially the p array is initialized to1;
    int l=1,r=1;
    for(int i=1;i<n-1;i++)
    {
        p[i]=max(0,min(r-i,p[l+r-i]));
        while(i+p[i]<n && i-p[i]>=0 && s[i-p[i]]==s[i+p[i]])
        {
            p[i]++;
        }

        if(i+p[i]>r)
        {
            l=i-p[i];
            r=i+p[i];
        }

    }
  }

  void build(string s)
  {
    string t;
    for(auto v:s)
    {
        t+=string("#")+v;
    }
    // for(int i=0;i<t.length();i++)
    // {
    //     cout<<t[i]<<" ";
    // }
    // cout<<"#"<<endl;
    // cout<<t.size()<<endl;
    run_manacher(t+'#');
  }

}m;
void solve()
{
  string s;
  cin>>s;
  m.build(s);
  bool isEven=true;
//   cout<<p.size()<<endl;
//    for(int i=0;i<=p.size();i++)
//   {
//     cout<<i<<" ";
//   }
//   cout<<endl;
//   for(int i=0;i<=p.size();i++)
//   {
//     cout<<p[i]<<" ";
//   }
//   cout<<endl;
   int first_index;
   int maxi=-1e9;
  for(int i=0;i<p.size();i++)
  {
     maxi=max(maxi,p[i]);

       }

    for(int i=0;i<p.size();i++)
  {
    if(maxi==p[i])
     {first_index=i;
     if(i%2!=0)
      isEven=false;
       break;
     }

       }     

    //    cout<<maxi<<" "<<first_index<<endl;
       if(isEven)
       {
       int l =first_index/2-(p[first_index]-1)/2;
    //    cout<<l<<" "<<r<<endl;
       cout<<s.substr(l,p[first_index]-1)<<endl;
       }

       else
       {
         int l =first_index/2-(p[first_index]-1)/2;
      
    //    cout<<l<<" "<<endl;
       cout<<s.substr(l,p[first_index]-1)<<endl;
       }


}
int main()
{
    int t ;
    cin>>t;
    while(t--)
    {
        solve();
    }




    return 0;
}