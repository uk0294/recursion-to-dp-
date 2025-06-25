// Write your code here
#include<bits/stdc++.h>
using namespace std;

#define int long long
vector<int>seive(int n )
{

    vector<int>primes;
    vector<bool>is_prime(n+1,true);
    is_prime[0]=false;
    is_prime[1]=false;

    for(int i=2;i<=n;i++)
    {
        if(is_prime[i])
        {
            primes.push_back(i);
            for(int j=1LL*i*i ;j<=n;j+=i)
            {
                is_prime[j]=false;
            }
        }
    }

    return primes;
}

vector<int>segmented_seive(int l , int r )
{

    //phase 1  - using the seieve method to get the primes uptill sqrt of r 
     int s1=ceil(sqrt(r));
     vector<int>base_prime=seive(s1);
   //phase 2 
     vector<bool> is_prime(r-l+1, true);
    // if(l == 1) is_prime[0] = false;  // when teh starting position is 1 then we use this 
       if(l <= 1) {  // CHANGE 1: Handle when l <= 1
        if(l == 1) is_prime[0] = false;  // 1 is not prime
        if(l <= 0) is_prime[1-l] = false;  // Handle negative numbers if needed
    }

    // now looping over the complete base primes and finding the first multiple of baseprime after the sqrt of r , 

    for(auto prime : base_prime)
    {

        int nmL=(l+prime-1)/prime; //gives multiplier for the  next multiple of prime after the l 
        int cur_mul=nmL*prime; // gives the current multiplier after l 
        cur_mul=max(prime*prime,cur_mul); // this ensures it does not marks composite aas it self and it make^2
        // now going forward until the cur_mul does not reach r
        while(cur_mul<=r)
        {
            is_prime[cur_mul-l]=false; // wea re starting from l , so cur_mul me se l ko ghataya
            cur_mul+=prime;// e.g prime =7 , cur_mul=56 , r= 100 
            // so it goes on increasing cur_mul like 56+7=63, 63+7=70 and so on uptill 100
        }

    }


    vector<int>final_primes;
    for(int i =0;i<r-l+1;i++)
    {
        if(is_prime[i])
         final_primes.push_back(i+l);
    }
    // sort(final_primes.begin(),final_primes.end());  // donot need this 
    return final_primes;
}
void solve()
{
    int l,r;
    cin>>l>>r;
    vector<int>ans;
    ans=segmented_seive(l,r);
    cout<<ans.size()<<endl;
    for(auto v:ans)
    {
        cout<<v<<" ";
    }
    cout<<endl;
    
   

}
signed main()

{
    solve();

    return 0;
}