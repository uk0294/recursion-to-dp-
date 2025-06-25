#include<bits/stdc++.h>
using namespace std;
int arr[200000];

struct node{
    long long sum;
    long long lazy_add;
    long long lazy_set;
    
    node(long long s=0,long long k=0,long long d) {
        sum = s;
        lazy_add=k;
        lazy-set=d;

    }
};
node t[800000];

node merge(node a , node b)
{
   node ans;
   ans.sum=a.sum+b.sum;
   return ans;  // no need to think of the lazy it will automatically be passed on  
}

void push(int id , int l , int r)
{
    if(i[id].lazy!=0) //agar lazy tabhi to push karoge na 
    {
         t[id].sum+=t[id].lazy*(r-l+1); // sum 


         if(l!=r) // add lazy  to left and right child 
         {
            t[id*2].lazy+=t[id].lazy;
            t[id*2+1].lazy+=t[id].lazy;
         }

         // clear
         t[id].lazy=0;
    }
}

void build(int id, int l, int r) {
    if(l == r) {
        t[id].sum = arr[l];
        t[id].lazy=0;
        return;
    }
    int mid = (l + r) / 2;
    build(2*id, l, mid);
    build(2*id+1, mid+1, r);
    t[id].sum = t[2*id].sum + t[2*id+1].sum;
}


void update_range_add(int id, int l, int r, int lq, int rq, long long val) {
    push(id, l, r);
    if(l > rq || r < lq) return;
    
    if(lq <= l && r <= rq) {
        t[id].lazy_add += val;
        push(id, l, r);
        return;
    }
    
    int mid = (l + r) / 2;
    update_range_add(2*id, l, mid, lq, rq, val);
    update_range_add(2*id+1, mid+1, r, lq, rq, val);
    
    push(2*id, l, mid);
    push(2*id+1, mid+1, r);
    t[id].sum = t[2*id].sum + t[2*id+1].sum;
}

void update_range_set(int id, int l, int r, int lq, int rq, long long val) {
    push(id, l, r);
    if(l > rq || r < lq) return;
    
    if(lq <= l && r <= rq) {
        t[id].lazy+=val; 
        push(id, l, r);
        return;
    }
    
    int mid = (l + r) / 2;
    update_range_set(2*id, l, mid, lq, rq, val);
    update_range_set(2*id+1, mid+1, r, lq, rq, val);
    
    t[id]=merge(t[id*2],t[id*2+1]);
}

long long query(int id, int l, int r, int lq, int rq) {
    if(l > rq || r < lq) return 0;
    push(id, l, r);
    
    if(lq <= l && r <= rq) {
        return t[id].sum;
    }
    
    int mid = (l + r) / 2;
    return query(2*id, l, mid, lq, rq) + query(2*id+1, mid+1, r, lq, rq);
}

void solve() {
    int n, q;
    cin >> n >> q;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    build(1, 0, n-1);
    
    while(q--) {
        int type;
        cin >> type;
        
        if(type == 1) {
            int a, b, x;
            cin >> a >> b >> x;
            update_range_add(1, 0, n-1, a-1, b-1, x);
        }
        else if(type == 2) {
            int a, b, x;
            cin >> a >> b >> x;
            update_range_set(1, 0, n-1, a-1, b-1, x);
        }
        else {
            int a, b;
            cin >> a >> b;
            cout << query(1, 0, n-1, a-1, b-1) << "\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}