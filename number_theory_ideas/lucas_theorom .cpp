#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        long long n;
        cin >> n;
        
        // Count number of set bits (1s) in binary representation of n
        int setBits = 0;
        long long temp = n;
        
        while (temp > 0) {
            if (temp & 1) {
                setBits++;
            }
            temp >>= 1;
        }
        
        // Number of odd binomial coefficients = 2^setBits
        long long oddCount = 1LL << setBits;
        
        // Number of even binomial coefficients = (n+1) - oddCount
        long long evenCount = (n + 1) - oddCount;
        
        cout << evenCount << " " << oddCount << endl;
    }
    
    return 0;
}