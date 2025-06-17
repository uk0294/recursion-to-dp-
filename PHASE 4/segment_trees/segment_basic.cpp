// Write your code here
#include<bits/stdc++.h>
using namespace std;
#define int long long
int arr[200001];
int t[800004];  // note always keep the tree size 4*arr size because we are building the tree in a way such that every node in two parts , 2*i , 2*i+1

//this builds the tree , with arr elements starting from l and ending till r 
void build(int index,int l, int r)
{
    //note the t[index] stores the sum from that particular l to r 
    if(l==r)  // l==r means the leaf node condition - for example 2-2 or 1-1 , which is arr[l] or arr[r]
     {
       t[index]=arr[l];
       return ;
     }

     int mid=(l+r)/2;
     build(index*2,l,mid);
     build(index*2+1,mid+1,r);
     t[index]=t[2*index]+t[2*index+1]; // buliding the parent by summing the two leaf nodes
}

// update the index i with the value x
void update (int index,int l , int r,int i, int x)
{
    if(i<l||i>r)  return ;
    if(l==r)
    {
        arr[i]=x;           // FIXED: Update array first
        t[index]=arr[i];    // Then update tree
        return ;
    }

    int mid=(l+r)/2;
    update(index*2,l,mid,i,x);
    update(index*2+1,mid+1,r,i,x);
    t[index]=t[2*index]+t[2*index+1];
}

//return sum from i to j 
int querys(int index,int l, int r, int i , int j)
{
   /* In a segment tree query, we want to return t[index] (the precomputed sum for the current segment) when the query range completely contains the current segment.
Let's say:

Current segment: [l, r]
Query range: [i, j]

We want to return t[index] when the query range [i, j] completely covers the segment [l, r].
For [i, j] to completely contain [l, r]:

i must be ≤ l (query starts at or before segment start)
j must be ≥ r (query ends at or after segment end)*/

    if(i>r || j<l) return 0;  // this check that i and j are never going out
    if(i<=l&&j>=r)  // FIXED: Corrected range check condition , basically when 
    {
       // if within the range then just return the sum which is stored in t
       return t[index];
    }
    int mid=(l+r)/2;
    return(querys(index*2,l,mid,i,j)+querys(index*2+1,mid+1,r,i,j)); // returning the sum of left child and right 
}

void solve()
{
    int n ,q;
    cin>>n>>q;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    build(1,0,n-1);
    for(int i=0;i<q;i++)
    {
        int ch ;
        cin>>ch;
        if(ch==1)
        {
            int i,x;
            cin>>i>>x;
            i--;  // FIXED: Convert to 0-based indexing
            // update the ith index with the x 
            update(1,0,n-1,i,x);
        }
        else
        {
            int i,j;
            cin>>i>>j;
            i--; j--;  // FIXED: Convert to 0-based indexing
            //returns sum from l to r 
            cout<<querys(1,0,n-1,i,j)<<endl;
        }
    }
}

signed main()
{
    solve();
    return 0;
}