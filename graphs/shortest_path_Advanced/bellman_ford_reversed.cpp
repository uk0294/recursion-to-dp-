#include<bits/stdc++.h>
using namespace std;
#define INF 1e18  // Use long long for distances to avoid overflow
#define F first
#define S second

// this is way of defining  , classes and objects
struct Edge {
    int from, to;
    long long weight;
};

vector<Edge> edges;  // Store all edges
vector<long long> dis;  // Distance array
int n, m;

void bellman_ford_longest_path(int start) {
    // Initialize distances - for longest path, start with -INF
    dis.assign(n + 1, -INF);
    dis[start] = 0;  // Distance to start node is 0
    

    // remember we relax edges v-1 times where v= vertices = no. of nodes;
    // Relax edges (n-1) times for longest path   
    //below implementation is for longest path so we can reverse the relaxing condition
    // In longest path, we want to MAXIMIZE distance
    for(int i = 0; i < n - 1; i++) {
        bool updated = false;
        for(auto& edge : edges) {
            // Only relax if we can reach the 'from' node  - kind of visited maintainanse
            if(dis[edge.from] != -INF) {
                // opposite relxation condition
                // For longest path: if current path through edge.from is longer
                if(dis[edge.to] < dis[edge.from] + edge.weight) {
                    dis[edge.to] = dis[edge.from] + edge.weight;
                    updated = true;
                }
            }
        }
        // If no updates in this iteration, we can break early
        if(!updated) break;
    }
    
    // Check for positive cycles reachable from start
    // Run one more iteration - if any distance increases, there's a positive cycle
    vector<bool> has_pos_cycle(n + 1, false);

    // to detect the positive cycle run the above same loop for n times on every node
    
    for(int i = 0; i < n; i++) {  // Run n times to propagate positive cycle detection


        for(auto& edge : edges) {

            if(dis[edge.from] != -INF) {
                
                // If we can still improve the distance, there's a positive cycle
                if(dis[edge.to] < dis[edge.from] + edge.weight) {
                    dis[edge.to] = dis[edge.from] + edge.weight;
                    has_pos_cycle[edge.to] = true;
                }
                // If 'from' node is affected by positive cycle, 'to' node is also affected
                if(has_pos_cycle[edge.from]) {
                    has_pos_cycle[edge.to] = true;
                }
            }
        }
    }
    
    // If target node n is affected by positive cycle, return -1
    if(has_pos_cycle[n]) {
        cout << -1 << endl;
        return;
    }
    
    // Otherwise return the longest distance to node n
    cout << dis[n] << endl;
}

void solve() {
    cin >> n >> m;
    
    // Clear previous data
    edges.clear();
    
    // Read all edges
    for(int i = 0; i < m; i++) {
        int a, b;
        long long w;
        cin >> a >> b >> w;
        edges.push_back({a, b, w});  // Directed edge from a to b with weight w
    }
    
    bellman_ford_longest_path(1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // Note: Based on your problem statement, it seems like single test case
    // If multiple test cases, uncomment below:
    /*
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    */
    
    solve();  // Single test case
    return 0;
}