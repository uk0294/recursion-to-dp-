#include<bits/stdc++.h>
using namespace std;
#define int long long
#define f first
#define s second


int n ,m;
vector<pair<int,pair<int,int>>>edges; // cost , {x,y};
vector<int>parent;
vector<int>rankk;

void init()
{
 parent.resize(n+1);
  rankk.resize(n+1);
   for(int i=1;i<=n;i++)
   {
    parent[i]=i;
    rankk[i]=1;  /// initilize rank with 1 otherwise will always give 0;
   }
}

int find(int x)
{
    if(parent[x]!=x)
    {

        parent[x]=find(parent[x]);
    }
    return parent[x];
}


bool unite(int x,int y)
{

    int xroot=find(x),yroot=find(y);
    if(xroot==yroot) return false;
    if(rankk[xroot]<rankk[yroot])
    {
        parent[xroot]=yroot;
         rankk[yroot]+=rankk[xroot];
    }
       else 
    {
        parent[yroot]=xroot;
         rankk[xroot]+=rankk[yroot];
    }

  
   
   return true;


}

void solve()
{
    cin>>n;
    m=n-1;
    init();
       edges.clear();
    for(int i=0;i<m;i++)
{

    int a,b,c;
    cin>>a>>b>>c;
    edges.push_back(make_pair(c,make_pair(a,b)));
}

sort(edges.begin(),edges.end());
reverse(edges.begin(),edges.end());  // for getting the highest cost 

int cnt=0;
int total_cost=0;
for(auto v:edges)
{
    int cost=v.f;
    int x =v.s.f;
    int y=v.s.s;
    if(find(x)!=find(y))
    {
        
     
        total_cost+=(rankk[find(x)]*rankk[find(y)]*cost);   // for finding the cost we are finding the rankk[dind(x)] , not the rank(x)
           unite(x,y);

    }
}


    cout<<total_cost<<endl;
 
}


signed main()
{
int t;
cin>>t;
while(t--)
solve();


    return 0;
}