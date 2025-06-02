#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
const int INF=1e9;
using state=pair<int,int>;
int n,m;
vector<vector<char>>g;
vector<vector<int>>visited;
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};

bool isValid(int x, int y)
{
    if(x >= 0 && y >= 0 && x < n && y < m && g[x][y] == '#')
    {
        return 1;
    }
    return 0;
}

vector<state>neighbours(state curr)
{
    vector<state>neighs;
    for(int i=0;i<4;i++)
    {
        int x=curr.F+dx[i];
        int y=curr.S+dy[i];
        if(isValid(x,y))
         neighs.push_back({x,y});
    }
    return neighs;
}

pair<int,int> dfs(state node, int num_comp)
{
    visited[node.F][node.S] = num_comp;
    int area = 1;
    int perimeter = 0;
    
    // Calculate perimeter contribution of current cell
    for(int i=0;i<4;i++)
    {
        int x = node.F + dx[i];
        int y = node.S + dy[i];
        if(x < 0 || y < 0 || x >= n || y >= m || g[x][y] != '#')
        {
            perimeter++;
        }
    }
    
    for(state v : neighbours(node))
    {
        if(visited[v.F][v.S] == 0)
        {
            pair<int,int> result = dfs(v, num_comp);
            area += result.first;
            perimeter += result.second;
        }
    }
    return make_pair(area, perimeter);
}

int main() {
    cin >> n;
    m = n; // Grid is N x N
    g.resize(n); 
    visited.assign(n, vector<int>(m, 0));
    
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        g[i].resize(m);
        for(int j = 0; j < m; j++)
        {
            g[i][j] = s[j];
        }
    }
    
    int num_comp = 0;
    vector<int> areas;
    vector<int> perimeters;
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(g[i][j] == '#' && visited[i][j] == 0)
            {
                num_comp++;
                pair<int,int> result = dfs(make_pair(i,j), num_comp);
                areas.push_back(result.first);
                perimeters.push_back(result.second);
            }
        }
    }
    
    int max_area = *max_element(areas.begin(), areas.end());
    int min_perimeter = INF;
    
    for(int i = 0; i < num_comp; i++)
    {
        if(areas[i] == max_area)
        {
            min_perimeter = min(min_perimeter, perimeters[i]);
        }
    }
    
    cout << max_area << " " << min_perimeter << endl;
    
    return 0;
}