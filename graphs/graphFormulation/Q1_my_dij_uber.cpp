#include<bits/stdc++.h>
using namespace std;
using ii = pair<int,int>;
#define MP make_pair
#define F first
#define S second
#define INF 1e18
#define int long long

struct Edge {
    int from, to;
    int distance;
    bool is_directed;
};

vector<Edge> edges;
vector<vector<pair<int,int>>> adj; // adjacency list for efficiency
int n, m, cap;
int cost[10001];
int dist[10001][101];
bool vis[10001][101];

using state = pair<int,int>;

void dijkstra(state st) {
    priority_queue<pair<int,ii>>pq;
    pq.push(MP(0, st));
    dist[st.F][st.S] = 0;
    
    while (!pq.empty()) {
        auto curr = pq.top();
       int curr_cost = -curr.F;
        auto curr_state = curr.S;
        pq.pop();

        if (vis[curr_state.F][curr_state.S]) continue;
        vis[curr_state.F][curr_state.S] = true;
        
        int curr_node = curr_state.F;
        int curr_fuel = curr_state.S;
        
        // Option 1: Refuel at current city (if not at full capacity)
        if (curr_fuel < cap && !vis[curr_node][curr_fuel + 1]) {
            int new_cost = curr_cost + cost[curr_node];
            if (dist[curr_node][curr_fuel + 1] > new_cost) {
                dist[curr_node][curr_fuel + 1] = new_cost;
                pq.push(MP(-new_cost, MP(curr_node, curr_fuel + 1)));
            }
        }
        
        // Option 2: Travel to neighboring cities
        for (auto& edge : adj[curr_node]) {
            int neighbor = edge.F;
            int fuel_needed = edge.S;
            
            // Check if we have enough fuel to reach the neighbor
            if (curr_fuel >= fuel_needed) {
                int remaining_fuel = curr_fuel - fuel_needed;
                if (!vis[neighbor][remaining_fuel]) {
                    // Cost remains same for traveling (only fuel is consumed)
                    if (dist[neighbor][remaining_fuel] > curr_cost) {
                        dist[neighbor][remaining_fuel] = curr_cost;
                        pq.push(MP(-curr_cost, MP(neighbor, remaining_fuel)));
                    }
                }
            }
        }
    }
}

void solve() {
    cin >> n >> m;
    
    adj.clear();
    adj.resize(n + 1);
    
    for (int i = 0; i < m; i++) {
        int a, b, d;
        cin >> a >> b >> d;
        
        // Add undirected edges to adjacency list
        adj[a].push_back({b, d});
        adj[b].push_back({a, d});
    }

    for (int i = 1; i <= n; i++)
        cin >> cost[i];
        
    int st_node, en_node;
    cin >> st_node >> en_node >> cap;
    
    // Initialize distance and visited arrays
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= cap; j++) {
            dist[i][j] = INF;
            vis[i][j] = false;
        }
    }
    
    state st = {st_node, 0}; // Start with 0 fuel
    dijkstra(st);
    
    // Find minimum cost to reach end node with any fuel amount
   int ans = INF;
    for (int i = 0; i <= cap; i++) {
        ans = min(ans, dist[en_node][i]);
    }
    
    cout << ans << "\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    solve();
    
    return 0;
}