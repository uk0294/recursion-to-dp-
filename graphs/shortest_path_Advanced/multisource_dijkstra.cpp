#include<bits/stdc++.h>
using namespace std;
#define INF 1e18
#define F first
#define S second
// in this problem the dijsktra code , remained the smae jut making of g is the critical part 
vector<vector<array<int,2>>> g;  // [[{node,weight}, {node,weight}], ...]
vector<long long> dis;
int n, a, b;
vector<int> arr;

void dijkstra(int start) {
    priority_queue<pair<long long, int>> pq;
    pq.push({0, start});   // Push {-distance, node}
    dis[start] = 0;
    
    while(!pq.empty()) {
        auto curr = pq.top();
        long long curr_dist = -curr.F;  // storing the -ve, because by default pq is max heap
        int curr_node = curr.S;
        pq.pop();
        
        if(curr_dist > dis[curr_node]) continue;   // Skip if we've already found a better path
        
        // Explore the neighbours of curr
        for(auto v : g[curr_node]) {
            // v[0] - node, v[1] - weight
            if(dis[v[0]] > dis[curr_node] + v[1]) {
                dis[v[0]] = dis[curr_node] + v[1];
                pq.push({-dis[v[0]], v[0]});  // push {-distance, node}
            }
        }
    }
}

void solve() {
    cin >> n >> a >> b;
    
    // We need up to 2*n nodes (original + super nodes)
    g.clear();
    g.resize(2 * n + 10); 
    dis.assign(2 * n + 10, INF);
    arr.resize(n + 1);
    
    // Read array elements
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    
    // Build the graph
    // 1. Connect adjacent indices with cost b
    for(int i = 1; i <= n; i++) {
        if(i > 1) {
            g[i].push_back({i - 1, b});  // connect to left neighbor
        }
        if(i < n) {
            g[i].push_back({i + 1, b});  // connect to right neighbor
        }
    }
    
    // 2. Create super nodes for same-valued indices
    map<int, vector<int>> same_value; // value -> list of indices
    for(int i = 1; i <= n; i++) {
        same_value[arr[i]].push_back(i);
    }
    
    int super_node = n + 1; // Start super nodes from n+1
    for(auto& group : same_value) {
        vector<int>& indices = group.second;
        
        // Only create super node if there are multiple indices with same value
        if(indices.size() > 1) {
            for(int idx : indices) {
                // From original node to super node: cost a
                g[idx].push_back({super_node, a});
                // From super node to original node: cost 0
                g[super_node].push_back({idx, 0});
            }
            super_node++;
        }
    }
    
    int src;
    cin >> src;
    
    dijkstra(src);
    
    // Output distances to original indices only (1 to n)
    for(int i = 1; i <= n; i++) {
        cout << dis[i] << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int t = 1;
    // cin >> t;  // single test case as per problem
    while(t--) {
        solve();
    }
    return 0;
}