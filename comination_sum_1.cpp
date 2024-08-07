
// the link to leetcode problem - https://leetcode.com/problems/combination-sum/description/
#include<bits/stdc++.h>
#define fr(i,a,b) for(int i=a;i<b;i++)
#define ll long long
#define ld long long
using namespace std;
class Solution {
public:
   void sum(int i,vector<int>&arr,vector<int>&curr,int target,vector<vector<int>>&ans ,int n ) // here we are passing many variables and particularl i is passed to avoid redudancy of same output , because there maybe cahance that r
   {// because we donot want the loop to start from a particular no. so we use variable i 

    if(target==0) // as soon as the target reaces 0 we pus and return the ans 
    {
        ans.push_back(curr);
        return ;
    }
    for(int j=i;j<n;j++)
    {
        if(j!=i&&arr[j]==arr[j-1]) // skipping the two consecutive same no. in array 
        continue;
        if(arr[j]>target)break;  // as we are using a sorted array so whenever a no. is > than target ethen loop breaks 

        curr.push_back(arr[j]); // pushing the term in array 
      
        sum(j,arr,curr,target-arr[j],ans,n);  // caling the loop again 
        curr.pop_back(); // poppun te last element to explore further as for each node there are two possibilities 

    }
   }
   
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end())  ;
        int n=candidates.size();

        vector<int >curr;
        vector<vector<int>>ans;
        sum(0,candidates,curr,target , ans, n);
    
       return ans ;
    }
};
int main(){
 ios_base::sync_with_stdio(false);
 cin.tie(NULL);
 cout.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
        
    }
    return 0;
}