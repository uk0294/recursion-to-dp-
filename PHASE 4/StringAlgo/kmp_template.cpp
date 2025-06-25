#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n ;
    cin>>n;
    string s;
    cin>>s;
    int kmp[n+1];
    kmp[0]=-1;
    int i=0,j=-1;
    while(i<n)
    {
        while(j!=-1 && s[i]!=s[j])
          j=kmp[j];
        i++;
        j++;
        kmp[i]=j;
    }

    for(int i=2;i<=n;i++)
    {
        int check=i-kmp[i];
        if(i%check==0)
        {
            int k =i/check;
            if(k>1)
             cout<<i<<" "<<k<<endl;
        }
       
    }
    
}
int main()
{


   int t;
   cin>>t;
   int case_num=1;
   while(t--)
    { 
         cout << "Test case #" << case_num << "\n";  // Print test case header
        solve();
        cout<<endl;
        case_num++;
    }
    return 0;
}