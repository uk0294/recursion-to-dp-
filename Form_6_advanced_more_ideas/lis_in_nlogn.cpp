#include<bits/stdc++.>
using namespace std;

void solve()
{
    int n;
    cin>>n;
     vector<int>arr;
     for(int i=0;i<n;i++)
     {
        cin>>arr[i];
     }

     vector<int>lis;
     vector<int>insertedat;

     for(int i=0;i<n;i++)
     {
        if(lis.empty()||lis.back()<arr[i])
         {
            lis.push_back(arr[i]);
            insertedat[i].lis.size()
         }

         else 
         {
            auto it = lower_bound(lis.begin(),lis.end(),arr[i]);   //finds the element >= arr[i]
            *it=arr[i];
            insertedat[i]=it-lis.begin()+1;
         }

         cout<<i<<" : ";
         for(auto v:lis)
         {
            cout<<lis<<" ";
         }
         cout<<endl;
     }



     // printing the lis 
     int curr_len=lis.size();
     vector<int>final_lis;
     for(int i=n-1;i>=0;i--)
     {
        if(insertedat[i]=curr_len)
        {
            final_lis.push_back(arr[i]);
            curr_len--;
        }
     }


     reverse(final_lis.begin(),final_lis.end()); 
}
int main()
{




    return 0;
}