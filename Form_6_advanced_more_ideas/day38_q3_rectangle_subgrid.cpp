#include<bits/stdc++.h>
using namespace std;

int arr[1005][1005]; // Reduced size for safety

void solve()
{
    int n, m;
    cin >> n >> m;
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
            cin >> arr[i][j];
    }
    
    long long ans = -2e18;
    
    // Optimization: iterate over smaller dimension 
    if(n >= m)
    {
        // Fix column boundaries and apply Kadane's on rows
        for(int c1 = 0; c1 < m; c1++)
        {
            vector<long long> row_sum(n, 0);  // maintains the row sum , before moving to next column 
            
            for(int c2 = c1; c2 < m; c2++)  
            {   
                // looping over to two columns and finfng the next next row sum , means , moving to different column , thinkoff like expanding horizontally
        
                // Add current column to row sums

                // there are two possibilites 
                //1. in a column(1D) take maximum sum of each element , means - finding the highest sum elemts in column
                //2. taking maximum of the elements - it is done when the no. is all negative , because finding the sum will reduce the sum 


                // the below two variables only defined to calculate row sum in case of the all negatives 
                bool all_negative = true;
                long long max_single = -2e18;
                
                for(int r = 0; r < n; r++)
                {
                    row_sum[r] += arr[r][c2];  // bulding the row sum - horizontal expansion
                    max_single = max(max_single, (long long)arr[r][c2]);  // finding the max of the elements for the all negative 
                    if(arr[r][c2] >= 0) all_negative = false;  // if any positive encountered
                }
                
                // Apply Kadane's algorithm on row_sum array
                if(all_negative)
                {
                    ans = max(ans, max_single); // directly return the max ans // option 2;
                }
                else
                {

                    // do option 1 , in a column do max sum of all 
                    long long kadane_sum = 0, max_sum = row_sum[0]; // initialll max sum = 1st element
                    for(int r = 0; r < n; r++)
                    {
                        kadane_sum += row_sum[r];// increased the element 
                        max_sum = max(max_sum, kadane_sum); // comparing with the first element initially 
                        kadane_sum = max(0LL, kadane_sum);// reinitialling the kadane sum to whenver negative - in case of negative it will become 0
                    }
                    ans = max(ans, max_sum);  // ans is obviosly the max sum 
                }
            }
        }
    }
    else
    {
        // Fix row boundaries and apply Kadane's on columns

        // just same thing for the row F
        for(int r1 = 0; r1 < n; r1++)
        {
            vector<long long> col_sum(m, 0);
            
            for(int r2 = r1; r2 < n; r2++)
            {
                // Add current row to column sums
                bool all_negative = true;
                long long max_single = -2e18;
                
                for(int c = 0; c < m; c++)
                {
                    col_sum[c] += arr[r2][c];
                    max_single = max(max_single, (long long)arr[r2][c]);
                    if(arr[r2][c] >= 0) all_negative = false;
                }
                
                // Apply Kadane's algorithm on col_sum array
                if(all_negative)
                {
                    ans = max(ans, max_single);
                }
                else
                {
                    long long kadane_sum = 0, max_sum = col_sum[0];
                    for(int c = 0; c < m; c++)
                    {
                        kadane_sum += col_sum[c];
                        max_sum = max(max_sum, kadane_sum);
                        kadane_sum = max(0LL, kadane_sum);
                    }
                    ans = max(ans, max_sum);
                }
            }
        }
    }
    
    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
    
    return 0;
}