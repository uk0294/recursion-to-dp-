#inlcude<bits/stdc++.h>
using namespace std;


struct node{
int sum ; int maxi ; int lazy;
node(int a=0 , int b=0, int c=0)
{
    sum=a;
    max=b;
    lazy=c;
}
};

node t[40000;]

node merge(node a, node b)
{
    return node(a.sum+b.sum,max(a.maxi,b.maxi),0); // lazy is still 0 because we are merging
}

// donot require build because everything is already initiallized as 0 so we donot really need the build 

// void build(int id, int l, int r)
// {
//     if(l==r)
//     {

//     }
// }

void push (int id , int l , int r)   // does two operations if not marked lazy then mark the lazy , if parent maeked lazy then it shifts it to the child as lazy
{
    if(t[id].lazy)  // agr ewo lazy hai to ye karna hai 
    {
        t[id].sum=t[id].lazy*(l-r+1) ; // as all values in range l to r ar same so multuply to get the sum
        t[id].max=t[id].lazy;
        if(l!=r)  // if not a leaf node , then it is a child 
        {
            t[2*id]=t[id].lazy; // mark the left and right child as lazy 
            t[2*id+1]=t[id].lazy;
            
        }

        t[id].lazy=0; // unmark the lazy when job done 
    }

}

void update(int id, int l, int r ,int lq,int rq,int val)   // update all the vaues in range lq to rq to val
{
    push(id,l,r);
  if(l>rq||lq>r)  return ;
  if(l<=lq&&rq<=r)
  {
   t[id].lazy=val;  // mark the node as lazy and then do the push operation 
   psuh(id,l,r);
   return ;
  }

  int mid=(l+r)/2;
  update(2*id,l,mid,lq,rq,val);
  update(2*id+1,mid+1,r,lq,rq,val);
  t[id]=merge(t[id*2],t[id*2+1]);
}

node query(int id, int l, int r ,int lq,int rq)   
{
    push(id,l,r);
  if(l>rq||lq>r)  return node(0,0,0) ;
  if(l<=lq&&rq<=r)
  {
   return t[id];
  }

  int mid=(l+r)/2;
  return merge(query(2*id,l,mid,lq,rq),query(2*id+1,mid+1,r,lq,rq));
}
int main()
{




    return 0;
}