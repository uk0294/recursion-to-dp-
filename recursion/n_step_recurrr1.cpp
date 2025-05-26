#include<bits/stdc++.h>
using namespace std;
//Q no. of ways to reach stairs n , you can take maximum upto 3 steps at a time 
//level- curr step , choice - 1/2/3 step , check - feasible step , move - move there

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
int rec(int level)//ret-> no. of ways to n iwe are at stair level
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

    //loop over choice
    for(int step=1;step<=3;step++)
    {
        if(level+step<=n)
        {
            //check -> is a vaild choice 

            int ways =rec(level+step);
            ans+=ways;

        }
    }
    return ans;
}
void solve()
{
    cin>>n;
    return rec(n);
}


int main()
{




    int t=1;
    //cin>>t;
    for(int i=0;i<t;i++)
    {
        solve(+)
    }
}