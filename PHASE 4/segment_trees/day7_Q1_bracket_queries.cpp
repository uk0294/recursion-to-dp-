// Write your code here
#include<bits/stdc++.h>
using namespace std;


string s;
struct node{
int op;
int cl;
int ma;
node(int o=0,int c=0,int m=0)
{
    op=o;
    cl=c;
    ma=m;
}

};
node t[4000004];
node merge (node a , node b)
{
    int t =min(a.op,b.cl);  // this gives that kitne closed configurations ban sakte ahi kyu ki open to a se hoga aur close b se , to dono ka jo min hoga utne *2 extra closed configurations to banega hi 

    // aur open bracet aur close bracket me se -t hoga kyu ki utna use ho rha hai closed configuration banaem total 2t loss dono mila ke jo ki ma me add ho rha 

    return (node(a.op+b.op-t,a.cl+b.cl-t,a.ma+b.ma+2*t));
}

void build(int index, int l , int r)
{
    if(l==r)  // leafnode
    {
        int op=0,cl=0,ma=0;

        if(s[l]=='(') op++;
        else if(s[l]==')') cl++;
       t[index]=node(op,cl,ma);

       return ;
    }

    int mid=(l+r)/2;
    build(2*index,l,mid);
    build(2*index+1,mid+1,r);
   t[index]= merge(t[2*index],t[2*index+1]);

} 

node query(int index, int l , int r, int lq, int rq)
{
    if(l>rq||r<lq) return node(0,0,0);
    if(l>=lq&&r<=rq)
    {

        return t[index];
    }
    int mid=(l+r)/2;
    
    return merge(query(2*index,l,mid,lq,rq),
    query(2*index+1,mid+1,r,lq,rq));
}
void solve()
{ 

    cin>>s;
    int n=s.size();
    build(1,0,n-1);
    int q;
    cin>>q;
    while(q--)
    {
        int l, r;
        cin>>l>>r;
        l--;
        r--;
        cout<<query(1,0,n-1,l,r).ma<<endl;
    }



}
int main()
{
  

   solve();


    return 0;
}