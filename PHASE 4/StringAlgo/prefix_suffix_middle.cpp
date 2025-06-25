#include<bits/stdc++.h>
using namespace std;

void solve()
{


     int n ;
     cin>>n;
     string s ;
     cin>>s;

    int kmp[n+1];
    kmp[0]=-1;
    int i=0,j=-1;
    while(i<n)
    {
        while(j!=-1 && s[i]!=s[j]) j=kmp[j];
        i++;
        j++;
        kmp[i]=j;
    }

    if(kmp[n]==0) {
        cout<<-1<<endl;
         return;
        }  // as we want to get to the next case also so doing continue 
    bool f=0;    // f means found in middle 
    for(int i=n-1;i>=1;--i)
    {
        if(kmp[i]==kmp[n])   // kmp[n-1] means the lsrgest prefix=suffix
        {
             // here we are searching that in the middle we maty get the same 
             //if we get then print the substr
             cout<<s.substr(0,kmp[n])<<endl; // longest prefix is printend
             f=1;
             break;
        }
    }

    if(f!=1)
    {
    if(kmp[kmp[n]]==0)  
    {
        cout<<-1<<endl;
    }
    else 
    {
        cout<<s.substr(0,kmp[kmp[n]])<<endl;
    }
    }

}
int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }



    return 0;
}