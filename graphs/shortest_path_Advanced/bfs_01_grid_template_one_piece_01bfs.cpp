// Write your code here// note bfs -01 is only done when there is possibilty of weighted graph which has weight of either 0 or 1
/*
  weight 1 push or initialize push
   back

  |    |
  |    |
  |    |        
  |    |
  ------
    weight 0 push and pop 
   front

*/
#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
#define F first
#define S second
vector<vector<int>>arr;  // initulized like this [[{1,0},{2,1}],[{3,1},{4,0}],....]
vector<vector<int>>dis;
int n, m;
using state=pair<int,int>;


// if we define the dx , dy this way it will be difficult in neighbour to initialize weight , then we nwwd to hardcode 
// int dx=[-1,1,0,0];
// int dy=[0,0,-1,1];
// defining dx , dy such that 0 - means right , 1- left , 2 -downn ,  3- up
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
bool check(int x, int y)
{
	if(x>=0 && y>=0 && x<n && y<m)
	  return 1;
	else return 0;
}

//passing and returning w as a parameter also 
// int w; donot initialize w as global make it inside as it can cause issue

vector<pair<state,int>> neighbour (state curr)
{
	    vector<pair<state,int>> neighs;
	for(int i=0;i<4;i++)
	{
		 int x=curr.F+dx[i];
        int y=curr.S+dy[i];
		// when wew use wrong  dx,dy then we need to use hardcoding
		//0-> means left - which means 2
		// if(i==0 && arr[x][y]==2)  w=0 else w=1 // similaarly we need to write for all 4 directions

		int w;
		if(i+1==arr[curr.F][curr.S]) w=0 ; else w=1;
		if(check(x,y))
		 neighs.push_back({{x,y},w});
		 
	}
	return neighs;
}                                                               

void bfs01(state node)
{
   deque<state>dq;
   dq.push_back({node.F,node.S});  // piche side dala taki pop hoke neighbours explore ho paye
   dis[node.F][node.S]=0;
   while(!dq.empty())
   {
       int currx=dq.front().F; //front element is the current // will explore the neighbours
	   int curry=dq.front().S;
       dq.pop_front();//popping the elements from the front
       //let; sexplore the neighbours of curr
       for(auto v: neighbour({currx,curry}))
       {
        // vist those neighbours who are not visited or those whose dist max still exsist
        // v[0] - 0th index gives node and v[1] - 1st index gives it's weight
		state next =v.F; // keep in mind it is not int 
		int w=v.S;  // as in the pair of neighbours , the first gives the elemeent second gives the weight
         if(dis[next.F][next.S]>dis[currx][curry]+w)
         {
            dis[next.F][next.S]=dis[currx][curry]+w;

            // if weigh is 0 then push_front else push_back
            if(w)
             {
                dq.push_back({next.F,next.S}); // push front what the current or the neighbours of curr, obviously the neighbours
             }

             else 
             {
                dq.push_front({next.F,next.S});
             }
         }
       }
   }
   
}

void solve()
{
cin>>n>>m;
// note assign overwrites all the array when moving to next tc, when using resize it does not overwrites
// whenever use resize and there are multiple tc always do clear
arr.clear();
arr.resize(n); //never forget this 
dis.assign(n,vector<int>(m,INF));  // dis array with infinity initilization
for(int i=0;i<n;i++)
{
    arr[i].resize(m); //donot forget this
    for(int j=0;j<m;j++)
    {
       cin>>arr[i][j];
    }
}

bfs01({0,0});
if(dis[n-1][m-1]==INF) cout<<"-1\n";
else cout<<dis[n-1][m-1]<<endl;

}

int main()
{ 

    // int t ;
    // cin>>t;
    // while(t--)
    // {
        solve();
    // }



    return 0;
}



################################################################################################################
above code done with neigbour can be done easily without neighbour 


// Write your code here// note bfs -01 is only done when there is possibilty of weighted graph which has weight of either 0 or 1
/*
  weight 1 push or initialize push
   back

  |    |
  |    |
  |    |        
  |    |
  ------
    weight 0 push and pop 
   front

*/
#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
#define F first
#define S second
vector<vector<int>>arr;  // initulized like this [[{1,0},{2,1}],[{3,1},{4,0}],....]
vector<vector<int>>dis;
int n, m;
using state=pair<int,int>;


// if we define the dx , dy this way it will be difficult in neighbour to initialize weight , then we nwwd to hardcode 
// int dx=[-1,1,0,0];
// int dy=[0,0,-1,1];
// defining dx , dy such that 0 - means right , 1- left , 2 -downn ,  3- up
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
bool check(int x, int y)
{
	if(x>=0 && y>=0 && x<n && y<m)
	  return 1;
	else return 0;
}
                                                          

void bfs01(state node)
{
   deque<state>dq;
   dq.push_back({node.F,node.S});  // piche side dala taki pop hoke neighbours explore ho paye
   dis[node.F][node.S]=0;
   while(!dq.empty())
   {
       int currx=dq.front().F; //front element is the current // will explore the neighbours
	   int curry=dq.front().S;
       dq.pop_front();//popping the elements from the front
       //let; sexplore the neighbours of curr
     for(int i=0;i<4;i++)
	 {

		int x=currx+dx[i];
		int y=xurry+dy[i];
         if(check(x,y))
           {
               // Fixed: Calculate weight correctly
               int w = (i+1==arr[currx][curry]) ? 0 : 1;
               
               // Fixed: Proper distance comparison
               if(dis[x][y]>dis[currx][curry]+w)
               {
                   dis[x][y]=dis[currx][curry]+w;

                   // Fixed: Corrected push logic
                   if(w==0)
                   {
                       dq.push_front({x,y});
                   }
                   else 
                   {
                       dq.push_back({x,y});
                   }
               }
           }
       }
   }
   
}

void solve()
{
cin>>n>>m;
// note assign overwrites all the array when moving to next tc, when using resize it does not overwrites
// whenever use resize and there are multiple tc always do clear
arr.clear();
arr.resize(n); //never forget this 
dis.assign(n,vector<int>(m,INF));  // dis array with infinity initilization
for(int i=0;i<n;i++)
{
    arr[i].resize(m); //donot forget this
    for(int j=0;j<m;j++)
    {
       cin>>arr[i][j];
    }
}

bfs01({0,0});
if(dis[n-1][m-1]==INF) cout<<"-1\n";
else cout<<dis[n-1][m-1]<<endl;

}

int main()
{ 

    // int t ;
    // cin>>t;
    // while(t--)
    // {
        solve();
    // }



    return 0;
}








