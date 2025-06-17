#include <iostream>
using namespace std;


void solve()
{
        vector<int> v={2,3,5};  // the vector for the divisors , means it should be divisible by only 2 or 5 or 3
        int k;
        cin>>k; // to find the kth ugly no.
        set<int>st;  // for storing the ugly no. in sorted order ,and it appears only one time 
        vector<int>ans; 
        st.insert(1);  // first ugly no. is always 1 
        while(ans.size()<k)  // keep on going until we have k ugly no.s 
        {
            ans.push_back(*st.begin());  // take the smalles element from the set 
            for(auto x:v)   // for all the multipliers which are in the v , which is 2 , 3 ,5 we want the potential candidates 
            {
                st.insert(*st.begin()*x); // generate the new candidates
                
            }

            st.erase(*st.begin());   // removed the used one<< 
        }

        cout<<ans.back()<<endl;

}


int main() {
    int t;
    cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}