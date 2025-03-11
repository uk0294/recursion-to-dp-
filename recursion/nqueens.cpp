#include<bits/stdc++.h>
using namespace std;
//Q no. of ways to place a queen on n*n chess board so that no two queen attack each other 
//level- row to place the queen  , choice - column to place  , check - previous queen donot, move - place and move there

// int rec(int level)
// {
//     for(all choices)
//     {
//         if(check(valid choice))
//         {
//             move(choice)
//         }
//     }
// }
int n ;

int queen[20]; // where is my queen in row i
bool check(int row , int col)
{
    for(int i=0;i<row;i++)
    {
        int prow=i;
        int pcol=queen[i];
        if(pcol==col|| abs(col-pcol)==abs(row-prow))
        {
            return 0;
        }

    }
    return 1;
}
int rec(int level)//rec-> ways to populate [level....n-1] ros for a valid  configuration
{
    //level->stairs ia m at
    
    //purning
    if(level>n){
        reurn 0;
    }
    //base case 
    if(level==n)
    {
        return 1;

    }
     //compute
    //loop over choice
    int ans=0;
    for(int col=0;col<n;col++)
    {

        if check(level,col)
        {   
        // place the queen explore the option
            queen[level]=col;
         //exploere that option
            ans+=rec(level+1);
            //revert placing the queen
            queen[level]=-1;


        }
    }
    //return 
    return ans;
}
void solve()
{
cin>>n;
memset(queen,-1,sizeof(queen));
cout<<rec(0)<<endl;
}


int main()
{




    int t=1;
    //cin>>t;
    for(int i=0;i<t;i++)
    {
        solve(t);
    }


    return 0;
}