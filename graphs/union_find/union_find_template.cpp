#include<bits/stdc++.h>
using namespace std;
vector<int>parent,rankk;
int q,n;



int find(int x)
{
    // agar wo khud ka parent na ho tabhi aage find karenge warna return the parentt
    if(parent[x]!=x)
    {
        parent[x]=find(parent[x]);
    }

    return parent[x];
}


void unite(int x, int y)
{
    int rootx=find(x);
    int rooty=find(y);
    if(rootx!=rooty) // only unite if they are in different sets 
    {
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

    }
}

bool same(int x , int y )
{
    if(find(x)==find(y))
      return 1;

    else 
     return 0;
}

//defining the new function which is init , thay initializes the parent and the rankk, initiaall the parent is  itself and rank is 0
void init() {
    parent.resize(n);
    rankk.resize(n);
    for(int i = 0; i < n; i++) {
        parent[i] = i;  // Each element is its own parent initially
        rankk[i] = 0;   // Initial rank is 0
    }
}

void solve()
{
   cin>>n;
   cin>>q;
     init();

   for(int i=0;i<q;i++)
    {
      int com;
      cin>>com;
      if(com==0)
      {

        int a , b ;
        cin>>a>>b;
        union(a,b);
      }

      else 
       {
        int a,b;
        cin>>a>>b;
        cout<<same(a,b)<<endl;
       }
        

    }
   
}
int main()
{






    return 0;
}