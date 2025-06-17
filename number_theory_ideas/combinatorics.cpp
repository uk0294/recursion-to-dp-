#include <iostream>
using namespace std;

const int MOD = 1000000007;

// Step 1: Calculate a^b mod MOD (fast exponentiation)
long long power(long long a, long long b) {
    long long result = 1;
    while (b > 0) {
        if (b % 2 == 1) {           // if b is odd
            result = (result * a) % MOD;
        }
        a = (a * a) % MOD;          // square the base
        b = b / 2;                  // halve the exponent
    }
    return result;
}

// Step 2: Calculate 1/a mod MOD
// Uses Fermat's Little Theorem: a^(p-1) = 1 mod p, so a^(p-2) = 1/a mod p
long long inverse(long long a) {
    return power(a, MOD - 2);
}

// Step 3: Calculate nCr = n! / (r! * (n-r)!) mod MOD
long long combination(int n, int r) {
    // Handle edge cases
    if (r < 0 || r > n) return 0;
    if (r == 0 || r == n) return 1;
    
    // Calculate nCr step by step to avoid overflow
    long long top = 1;      // This will be n * (n-1) * ... * (n-r+1)
    long long bottom = 1;   // This will be r!
    
    for (int i = 0; i < r; i++) {
        top = (top * (n - i)) % MOD;        // multiply by (n-i)
        bottom = (bottom * (i + 1)) % MOD;  // multiply by (i+1)
    }
    
    // Return top / bottom mod MOD
    return (top * inverse(bottom)) % MOD;
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    
    long long final_answer = 0;
    
    // The main inclusion-exclusion loop
    for (int j = 0; j <= n; j++) {
        
        // STEP A: Calculate remaining sum
        // If j variables are >= m, each contributes at least m
        // So remaining sum = k - j*m
        long long remaining_sum = k - (long long)j * m;
        
        // If remaining sum is negative, impossible case
        if (remaining_sum < 0) {
            break;  // No more valid cases
        }
        
        // STEP B: Count ways to choose which j variables are >= m
        long long ways_to_choose = combination(n, j);
        
        // STEP C: Count solutions with remaining sum
        // This is: how many ways to write remaining_sum as sum of n non-negative integers
        // Formula: C(n + remaining_sum - 1, n - 1)
        long long ways_to_distribute = combination(n + remaining_sum - 1, n - 1);
        
        // STEP D: Total ways for this case
        long long total_ways = (ways_to_choose * ways_to_distribute) % MOD;
        
        // STEP E: Add or subtract based on inclusion-exclusion
        if (j % 2 == 0) {
            // Even j: ADD (inclusion)
            final_answer = (final_answer + total_ways) % MOD;
        } else {
            // Odd j: SUBTRACT (exclusion)
            final_answer = (final_answer - total_ways + MOD) % MOD;
        }
    }
    
    cout << final_answer << endl;
    return 0;
}