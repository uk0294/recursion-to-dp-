#include<bits/stdc++.h>
using namespace std;

#define int long long

int arr[200005];
int n, q;

struct node {
    int sum;
    
    node(int e = 0) {
        sum = e;
    }
};

node t[800400];

node merge(node a, node b) {
    return node(a.sum + b.sum);
}

void build(int index, int l, int r) {
    if (l == r) {
        t[index].sum = 0;  // Initialize difference array with 0
        return;
    }
    
    int mid = (l + r) / 2;
    build(2 * index, l, mid);
    build(2 * index + 1, mid + 1, r);
    t[index] = merge(t[2 * index], t[2 * index + 1]);
}

void update(int index, int l, int r, int pos, int val) {
    if (pos < l || pos > r) return;
    
    if (l == r) {
        t[index].sum += val;
        return;
    }
    
    int mid = (l + r) / 2;
    update(2 * index, l, mid, pos, val);
    update(2 * index + 1, mid + 1, r, pos, val);
    t[index] = merge(t[2 * index], t[2 * index + 1]);
}

node query(int index, int l, int r, int lq, int rq) {
    if (l > rq || lq > r) return node(0);
    
    if (l >= lq && r <= rq) {
        return t[index];
    }
    
    int mid = (l + r) / 2;
    return merge(query(index * 2, l, mid, lq, rq), 
                 query(index * 2 + 1, mid + 1, r, lq, rq));
}

void solve() {
    cin >> n >> q;
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    build(1, 0, n - 1);
    
    while (q--) {
        int ch;
        cin >> ch;
        
        if (ch == 1) {
            int x, y, val;
            cin >> x >> y >> val;
            
            x--; y--;  // Convert to 0-based indexing
            
            // Range update using difference array technique
            update(1, 0, n - 1, x, val);
            if (y + 1 < n) {
                update(1, 0, n - 1, y + 1, -val);
            }
        }
        else {
            int pos;
            cin >> pos;
            pos--;  // Convert to 0-based indexing
            
            // Get prefix sum up to position pos and add original value
            int prefix_sum = query(1, 0, n - 1, 0, pos).sum;
            cout << arr[pos] + prefix_sum << "\n";
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    solve();
    
    return 0;
}