// here we will learn to compress the large valued array to idex with small value , so let's see how can it be done
/*What is Coordinate Compression?
Coordinate compression is a technique that maps large values to smaller consecutive indices (0, 1, 2, 3...). It's especially useful when you have:

Large values (like 10^9) but few unique elements
Need to use arrays indexed by these values
Want to avoid memory waste

Why Use Coordinate Compression?
Example: Array = [1, 1000000000, 2, 1000000000, 3]
Without compression: You'd need an array of size 10^9 → 1GB+ memory
With compression: Map values to indices:

1 → 0
2 → 1
3 → 2
1000000000 → 3

Now you only need array of size 4!
Time & Space Complexity Impact:

Space Complexity: Reduces from O(max_value) to O(unique_elements)
Time Complexity: Usually stays same, but operations become faster due to better cache locality

`*/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
// you can also do it without define the struct it's your choice 
Struct coordinateCompression
{
    map<int ,int>comp_val ; // first index stores the actual value and the second is the compressed value
    vector<int>rev_mapping; // it stores the actual val for the reverse mapping , you can assume like this , it stores actual val 
    void addCompVal(int x)   // x is the actual input from the array - given by user
    {
        comp_val[x];  // it creates {x,0} entrires in the map 

    }

    void build( int x)
    {
        int cnt=0;
        for(auto &v:comp_val)
        {
            rev_mapping.push_back(v.first);
            v.second=cnt++;// invreasing the count of the second index of the map ,you can think of like this {x,0},{y,1}. and so on 

        }
    }
    int get_comp_val(int x)
    {
        return comp_val[x];  // directly gives the compressed value of x 
    }

    int orig_val(int x)
    {
        return rev_mapping[x];
    }

    int prev_val(int x)
    {
        auto it =comp_val.upper_bound(x);  // returns >x
        it--; // as we want to get the previous so doing -- to get the value <=x
        return it->second;  // returs the just equal value or the prev 
    }
    int next_val(int x)  
    {
        auto it =comp_val.lower_bound(x); //gives >=x;
        return it->second;  // returns the just next value or the same value 
    }

}CMP;

void solve()
{    
    vector<int>arr={1,2,4,9,2,3}; // the input array 
for(auto v:arr)
{
    CMP.add(v); // getting compressed value for all 
}

CMP.build();
}
signed main()
{




    return 0;
}