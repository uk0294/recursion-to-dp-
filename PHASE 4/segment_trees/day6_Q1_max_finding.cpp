#include<bits/stdc++.h>
using namespace std;
#define int long long 
struct node
{
    int max_val;
    node(int e=0)
    {
        max_val=e;
    }

};

int arr[200005];  // take care of size of arr 
node t[800020];

node merge(node a , node b)
{
    return node(max(a.max_val,b.max_val));
}

void build (int index, int l, int r)
{
    // if(index<l||index>r) return ;  never do 
   if(l==r)
    {
        t[index].max_val=arr[l]; // that is only the min val
        return ;
    }

    int mid=(l+r)/2;
    build(index*2,l,mid);
    build(index*2+1,mid+1,r);
    t[index]=merge(t[index*2],t[index*2+1]);
}

void update(int index, int l , int r, int pos , int val)
{

    if(pos<l||pos>r) return ;
    if(l==r) 
    {
      arr[l]-=val;
      t[index].max_val=arr[l];
      return;
    }
      int mid=(l+r)/2;
    update(index*2,l,mid,pos,val);
    update(index*2+1,mid+1,r,pos,val);
   t[index]= merge(t[index*2],t[index*2+1]);
}

int query(int index, int l , int r, int reqVal) 
{
    if(reqVal>t[index].max_val)  return -1;  // Change: return -1 instead of 0

    if(l==r)
    {
         return l;
    }
    
    int mid=(l+r)/2;
    if(t[2*index].max_val>=reqVal)
    {
        return query(2*index,l,mid,reqVal);
    }

    else 
    {
        return query(2*index+1,mid+1,r,reqVal);
    }
}


void solve()
{
    int n , q;
    cin>>n>>q;  // Change: read both n and q together
    for(int i =0;i<n;i++)
    {
        cin>>arr[i];
    }

    build(1,0,n-1);
  
    // Remove the extra cin>>q; line here
    while(q--)
    {
        int a;
        cin>>a;
       int ans= query(1,0,n-1,a);
         if(ans>=0)
        update(1,0,n-1,ans,a);  // Change: use ans instead of ans-1
       cout<<ans+1<<" ";
     
    }
}
signed main()
{


    solve();

    return 0;
}