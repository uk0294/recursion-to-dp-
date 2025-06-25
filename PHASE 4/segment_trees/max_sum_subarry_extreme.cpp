#include<bits/stdc++.h>
using namespace std;

#define int long long
int arr[200005];
int n, q;

struct node {
    int max_sum;     // Maximum subarray sum in this range
    int left_sum;    // Maximum sum starting from leftmost element
    int right_sum;   // Maximum sum ending at rightmost element  
    int total_sum;   // Total sum of all elements in range
    
    node(int total = 0, int maxi = 0, int left = 0, int right = 0) {
        total_sum = total;
        max_sum = maxi;
        left_sum = left;
        right_sum = right;
    }
};

node t[800020];

// MERGE LOGIC - This is the heart of the solution!
node merge(node a, node b) {
    node result;
    
    // Total sum is simple - just add both parts
    result.total_sum = a.total_sum + b.total_sum;
    
    // Left sum: either take left part's left_sum OR take entire left part + right part's left_sum
    result.left_sum = max(a.left_sum, a.total_sum + b.left_sum);
    
    // Right sum: either take right part's right_sum OR take entire right part + left part's right_sum  
    result.right_sum = max(b.right_sum, b.total_sum + a.right_sum);
    
    // Maximum sum: can be from left part, right part, OR crossing the middle (a's right + b's left)
    result.max_sum = max({a.max_sum, b.max_sum, a.right_sum + b.left_sum});
    
    return result;
}

void build(int index, int l, int r) {
    if(l == r) {
        // For single element: all four values depend on whether element is positive or not
        int val = arr[l];
        int positive_val = max(val, 0LL);  // We can choose empty subarray (sum = 0)
        t[index] = node(val, positive_val, positive_val, positive_val);
        return;
    }
    
    int mid = (l + r) / 2;
    build(2 * index, l, mid);
    build(2 * index + 1, mid + 1, r);
    t[index] = merge(t[2 * index], t[2 * index + 1]);
}

void update(int index, int l, int r, int pos, int val) {
    if(pos < l || pos > r) return;
    
    if(l == r) {
        arr[l] = val;
        int positive_val = max(val, 0LL);
        t[index] = node(val, positive_val, positive_val, positive_val);
        return;
    }
    
    int mid = (l + r) / 2;
    update(2 * index, l, mid, pos, val);
    update(2 * index + 1, mid + 1, r, pos, val);
    t[index] = merge(t[2 * index], t[2 * index + 1]);
}

int query() {
    return t[1].max_sum;  // Root node has answer for entire array
}

void solve() {
    cin >> n >> q;
    
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    build(1, 0, n - 1);
    
    for(int i = 0; i < q; i++) {
        int k, x;
        cin >> k >> x;
        k--;  // Convert to 0-based indexing
        update(1, 0, n - 1, k, x);
        cout << query() << "\n";
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    solve();
    return 0;
}s