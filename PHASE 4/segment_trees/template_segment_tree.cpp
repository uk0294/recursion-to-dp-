// here we are given to count the no. of of odda nd even in range l to r  // day 5 Q1

// Write your code here
#include<bits/stdc++.h>
using namespace std;


#define int long long
int arr[10005];
int n ;
int q;

struct node{

 int cnt_even; 
   int cnt_odd;
  
   node(int e=0,int o=0)   // orderin in the nide matters vvi 
   {

   
    cnt_even=e;
     cnt_odd=o;
   }
}; // semi colon is must



node t[40040];
// we have two nides one on left and one on right and so on , left should be mergerd to the right so what can br the er merfet condition 
node merge (node a, node b)
{
   return node(a.cnt_even+b.cnt_even,a.cnt_odd+b.cnt_odd);  // sum the count of even and odd in every child node 

}


void build(int index,int l, int r)
{

    // if(index<l||index>r) return ;  // donot ever put this line 
    // if leaf node then check ki wo odd hai ki even agar even hua to even sum me badhao
    if(l==r) 
    {
       t[index]=node(arr[l]%2==0 ? 1 :0,arr[l]%2==1?1:0);  // agar odd hai to inc odd sum , even hai to inc even sum 
       return ;
    }

    int mid=(l+r)/2;
    build(2*index,l,mid);
    build(2*index+1,mid+1,r);
    t[index]=merge(t[2*index],t[2*index+1]);
}

void update (int index,int l , int r , int pos , int val)   // uss position ko value se update karo 
{
    if(pos<l||pos>r)  return ;
    if(l==r)
    {
         arr[l]=val;
         t[index]=node(val%2==0 ? 1:0,val%2==1?1:0);
         return ;
    }

     int mid=(l+r)/2;
    update(2*index,l,mid,pos ,val);
    update(2*index+1,mid+1,r,pos,val);
    t[index]=merge(t[2*index],t[2*index+1]);
    

}

node query(int index, int l , int r, int lq,int rq)
{
    //if no overlap the n return 0
    if(l>rq||lq>r) return node(0,0);


    // if overlap then anwer the quey 
    if(l>=lq && r<=rq)  
    {
       return t[index]; // return the index 
    }
    int mid=(l+r)/2;
    return merge(query(index*2,l,mid,lq,rq),query(index*2+1,mid+1,r,lq,rq));
}

void solve()
{
   cin>>n;
   for(int i=0;i<n;i++)
   {
    cin>>arr[i];
   }

    build(1,0,n-1);
   cin>>q;
   while(q--)
   {
     int ch ;
     cin>>ch;
     if(ch==0)
     {
        int x,y;
        cin>>x>>y;
        x--;  // must cionvert to one based indexing 
        update(1,0,n-1,x,y);
     }

     else if(ch==1)
     {
        int l ,r;
        cin>>l>>r;
        l--;
        r--;  // must convert to one based indexing 
        cout<<query(1,0,n-1,l,r).cnt_even<<endl;
     }

      else
     {
        int l ,r;
        cin>>l>>r;
        l--;
        r--;  // must convert to one based insexing , 
        cout<<query(1,0,n-1,l,r).cnt_odd<<endl;
     }
   }
}


signed main ()
{

    solve();

    return 0;
}