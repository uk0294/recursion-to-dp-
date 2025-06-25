// Maximum XOR Pair Problem - Find pair (i,j) such that A[i] XOR A[j] is maximum
#include<bits/stdc++.h>
using namespace std;

struct node{
    int child[2];
    int count_num;
    
    node()
    {
        child[0]=child[1]=-1;
        count_num=0;
    }
};

struct tries{
    vector<node> nodes;
    int MAXN=20; // as we are given uptill 10^6 no.s so the 2 power 20 is sufficient
    
    tries() {
        node root_node;
        nodes.push_back(root_node);
    }
    
    void insert(int no) {
        int curr_idx=0;
        // traverse from msb to lsb ie from 19 to 0
        for(int i=MAXN-1;i>=0;i--)
        {
            int bit =(no>>i)&1; // i position pe given no. ka kya bit hai 0 or 1
            
            if(nodes[curr_idx].child[bit]==-1) // agar child me kuch nhi hai to
            {
                node new_node;
                nodes.push_back(new_node);
                nodes[curr_idx].child[bit]=nodes.size()-1; // pointing the child node
            }
            nodes[curr_idx].count_num++;
            curr_idx=nodes[curr_idx].child[bit];
        }
        nodes[curr_idx].count_num++; // increment count at leaf node
    }
    
    int maxXorQuery(int number) {
        int curr_idx=0;
        int ans=0;
        
        for(int i=MAXN-1;i>=0;i--)
        {
            int curr_bit=(number>>i)&1; // Fixed: was (number>>1)&1
            int opp_bit=1-curr_bit;
            
            // so option hai , 1. agar ek corresponding bit ke koi opp bit wala available hai to wo lelo
            // ya 2 . proceed with the same bit , in this case ans will remain same as xor of two same no. is 0 so xor mat karna
            
            // option 1
            if(nodes[curr_idx].child[opp_bit]!=-1 && nodes[nodes[curr_idx].child[opp_bit]].count_num>0)
            {
                // now taking the xor
                ans|=(1<<i);
                curr_idx=nodes[curr_idx].child[opp_bit];
            }
            else
            {
                // option 2
                curr_idx=nodes[curr_idx].child[curr_bit];
            }
        }
        return ans;
    }
};

void solve()
{
    int n;
    cin>>n;
    
    tries trie;
    trie.insert(0); // Insert 0 for empty prefix
    
    int prefix_xor = 0;
    int max_xor = 0;
    
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        prefix_xor ^= a;
        max_xor = max(max_xor, trie.maxXorQuery(prefix_xor));
        trie.insert(prefix_xor);
    }
    
    cout << max_xor << endl;
}

int main() {
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}



#############################################################################################################################
#include<bits/stdc++.h>
using namespace std;

struct bit_node {
    int child[2];           // child[0] for bit 0, child[1] for bit 1
    int count_numbers;      // kitne numbers pass through this node
    
    bit_node() {
        child[0] = child[1] = -1;  // -1 means no child exists
        count_numbers = 0;
    }
};

struct max_xor_trie {
    vector<bit_node> nodes;
    int MAXBITS = 20;  // since max value is 10^6, 20 bits are sufficient (2^20 > 10^6)
    
    max_xor_trie() {
        bit_node root_node;
        nodes.push_back(root_node);
    }
    
    void insert(int number) {
        int curr_idx = 0;
        
        // MSB se LSB tak traverse karo (bit 19 to bit 0)
        for(int bit_pos = MAXBITS - 1; bit_pos >= 0; bit_pos--) {
            int bit = (number >> bit_pos) & 1;  // extract bit at position bit_pos
            
            // agar child exist nahi karta, create new node
            if(nodes[curr_idx].child[bit] == -1) {
                bit_node new_node;
                nodes.push_back(new_node);
                nodes[curr_idx].child[bit] = nodes.size() - 1;
            }
            
            curr_idx = nodes[curr_idx].child[bit];
            nodes[curr_idx].count_numbers++;  // count increase karo
        }
    }
    
    int find_max_xor_with(int number) {
        int curr_idx = 0;
        int max_xor_result = 0;
        
        // MSB se LSB tak traverse karo
        for(int bit_pos = MAXBITS - 1; bit_pos >= 0; bit_pos--) {
            int current_bit = (number >> bit_pos) & 1;
            int opposite_bit = 1 - current_bit;  // opposite bit chahiye max XOR ke liye
            
            // pehle opposite bit try karo (greedy approach for maximum XOR)
            if(nodes[curr_idx].child[opposite_bit] != -1 && 
               nodes[nodes[curr_idx].child[opposite_bit]].count_numbers > 0) {
                
                max_xor_result |= (1 << bit_pos);  // set bit in result (because bits are different)
                curr_idx = nodes[curr_idx].child[opposite_bit];
            } 
            else {
                // opposite bit available nahi hai, same bit lena padega
                curr_idx = nodes[curr_idx].child[current_bit];
                // max_xor_result me kuch add nahi karna (because bits are same, XOR = 0)
            }
        }
        
        return max_xor_result;
    }
    
    void debug_print_number_binary(int number) {
        cout << "Number " << number << " in binary: ";
        for(int i = MAXBITS - 1; i >= 0; i--) {
            cout << ((number >> i) & 1);
        }
        cout << endl;
    }
};

int solve_max_xor_pair(vector<int>& arr) {
    max_xor_trie trie;
    int n = arr.size();
    int maximum_xor_found = 0;
    
    cout << "=== Inserting all numbers into trie ===" << endl;
    // sabhi numbers ko trie me insert karo
    for(int i = 0; i < n; i++) {
        cout << "Inserting: " << arr[i] << endl;
        trie.insert(arr[i]);
    }
    
    cout << "\n=== Finding maximum XOR for each number ===" << endl;
    // har number ke liye maximum XOR find karo
    for(int i = 0; i < n; i++) {
        int current_max_xor = trie.find_max_xor_with(arr[i]);
        cout << "Max XOR with " << arr[i] << " is: " << current_max_xor << endl;
        
        maximum_xor_found = max(maximum_xor_found, current_max_xor);
    }
    
    return maximum_xor_found;
}

void detailed_example_dry_run() {
    cout << "=== DETAILED DRY RUN EXAMPLE ===" << endl;
    vector<int> example = {3, 10, 5, 25, 2, 8};
    
    cout << "Array: ";
    for(int x : example) cout << x << " ";
    cout << endl;
    
    cout << "\nBinary representations:" << endl;
    max_xor_trie temp_trie;
    for(int x : example) {
        temp_trie.debug_print_number_binary(x);
    }
    
    cout << "\nStep by step XOR calculations:" << endl;
    cout << "Let's see why 3 XOR 25 = 26 is maximum:" << endl;
    cout << "3  = 00000000000000000011" << endl;
    cout << "25 = 00000000000000011001" << endl;
    cout << "XOR= 00000000000000011010 = 26" << endl;
    
    cout << "\nSolution:" << endl;
    int result = solve_max_xor_pair(example);
    cout << "\nFinal Answer: " << result << endl;
}

void solve() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    
    vector<int> arr(n);
    cout << "Enter elements: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    int result = solve_max_xor_pair(arr);
    cout << "\nMaximum XOR pair value: " << result << endl;
}

int main() {
    cout << "Choose option:" << endl;
    cout << "1. Run detailed example with dry run" << endl;
    cout << "2. Input your own array" << endl;
    
    int choice;
    cin >> choice;
    
    if(choice == 1) {
        detailed_example_dry_run();
    } else {
        solve();
    }
    
    return 0;
}

/*
=== ALGORITHM EXPLANATION ===

Problem: Find pair (i,j) such that A[i] XOR A[j] is maximum

Key Insight: 
- XOR gives 1 when bits are different, 0 when same
- To maximize XOR, we want maximum number of differing bits
- For each bit position, we prefer the opposite bit (greedy approach)

Steps:
1. Insert all numbers into bit trie
2. For each number, find the number in trie that gives maximum XOR
3. Return the overall maximum

Why Trie Works:
- At each level, we can choose the path that maximizes current bit in result
- Greedy choice: always prefer opposite bit if available
- Time: O(N * 20) instead of O(N^2) brute force

Example Walkthrough:
Array: [3, 10, 5, 25, 2, 8]

Binary:
3  = 00011
10 = 01010  
5  = 00101
25 = 11001
2  = 00010
8  = 01000

For number 3 (00011):
- At bit 4: want 1 (opposite of 0), available in 25 → take it
- At bit 3: want 1 (opposite of 0), available in 25 → take it  
- At bit 2: want 1 (opposite of 0), not available → take 0
- At bit 1: want 1 (opposite of 1), available in 25 → take it
- At bit 0: want 0 (opposite of 1), not available → take 1

Result: 11010 = 26 (which is 3 XOR 25)

This is the maximum possible XOR value in the array.
*/