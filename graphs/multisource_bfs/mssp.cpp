#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9;
#define F first
#define S second
using state = pair<int, int>;

vector<vector<int>> distA;
vector<vector<int>> distMon;
vector<vector<char>> arr;
vector<state> monsters;
state st;

int n, m;

bool isValid(int x, int y)
{
    if(x >= 0 && y >= 0 && x < n && y < m && arr[x][y] != '#')
    {
        return 1;
    }
    return 0;
}

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

vector<state> neighbours(state curr)
{
    vector<state> neighs;
    for(int i = 0; i < 4; i++)
    {
        int x = curr.F + dx[i];
        int y = curr.S + dy[i];
        if(isValid(x, y))
        {
            neighs.push_back({x, y});
        }
    }
    return neighs;
}

void bfsMonsters()
{
    queue<state> q;
    distMon.assign(n, vector<int>(m, INF));
    
    for(state monster : monsters)
    {
        distMon[monster.F][monster.S] = 0;
        q.push(monster);
    }
    
    while(!q.empty())
    {
        state curr = q.front();
        q.pop();
        
        for(state v : neighbours(curr))
        {
            if(distMon[v.F][v.S] == INF)
            {
                distMon[v.F][v.S] = 1 + distMon[curr.F][curr.S];
                q.push(v);
            }
        }
    }
}

void bfsPlayer()
{
    queue<state> q;
    distA.assign(n, vector<int>(m, INF));
    distA[st.F][st.S] = 0;
    q.push(st);
    
    while(!q.empty())
    {
        state curr = q.front();
        q.pop();
        
        for(state v : neighbours(curr))
        {
            if(distA[v.F][v.S] == INF)
            {
                distA[v.F][v.S] = 1 + distA[curr.F][curr.S];
                q.push(v);
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    arr.resize(n);
    
    for(int i = 0; i < n; i++)
    {
        arr[i].resize(m);
        string s;
        cin >> s;
        for(int j = 0; j < m; j++)
        {
            arr[i][j] = s[j];
            if(arr[i][j] == 'A')
            {
                st = {i, j};
            }
            if(arr[i][j] == 'M')
            {
                monsters.push_back({i, j});
            }
        }
    }
    
    bfsMonsters();
    bfsPlayer();
    
    int minDist = INF;
    bool found = false;
    
    // Check all boundary cells
    for(int i = 0; i < n; i++)
    {
        // Left boundary
        if(arr[i][0] != '#' && distA[i][0] != INF)
        {
            if(distA[i][0] < distMon[i][0])
            {
                found = true;
                minDist = min(minDist, distA[i][0]);
            }
        }
        
        // Right boundary
        if(arr[i][m-1] != '#' && distA[i][m-1] != INF)
        {
            if(distA[i][m-1] < distMon[i][m-1])
            {
                found = true;
                minDist = min(minDist, distA[i][m-1]);
            }
        }
    }
    
    for(int j = 0; j < m; j++)
    {
        // Top boundary
        if(arr[0][j] != '#' && distA[0][j] != INF)
        {
            if(distA[0][j] < distMon[0][j])
            {
                found = true;
                minDist = min(minDist, distA[0][j]);
            }
        }
        
        // Bottom boundary
        if(arr[n-1][j] != '#' && distA[n-1][j] != INF)
        {
            if(distA[n-1][j] < distMon[n-1][j])
            {
                found = true;
                minDist = min(minDist, distA[n-1][j]);
            }
        }
    }
    
    if(found)
    {
        cout << "YES" << endl;
        cout << minDist << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    
    return 0;
}