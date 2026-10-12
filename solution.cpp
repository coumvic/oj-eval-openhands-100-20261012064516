#include <iostream>
#include <vector>
#include <cmath>
#include <cstdint>

using namespace std;

uint64_t sumProperDivisors(uint64_t n) {
    if (n <= 1) return 0;
    
    uint64_t sum = 1; // 1 is always a proper divisor for n > 1
    
    uint64_t sqrt_n = static_cast<uint64_t>(sqrt(n));
    
    for (uint64_t i = 2; i <= sqrt_n; ++i) {
        if (n % i == 0) {
            uint64_t divisor = i;
            uint64_t paired_divisor = n / i;
            
            if (divisor == paired_divisor) {
                // Perfect square, add only once
                sum += divisor;
            } else {
                // Add both divisors
                sum += divisor + paired_divisor;
            }
        }
    }
    
    return sum;
}

bool isPerfectNumber(uint64_t n) {
    return sumProperDivisors(n) == n;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int m;
    cin >> m;
    
    vector<uint64_t> numbers(m);
    for (int i = 0; i < m; ++i) {
        cin >> numbers[i];
    }
    
    for (int i = 0; i < m; ++i) {
        if (isPerfectNumber(numbers[i])) {
            cout << "1\n";
        } else {
            cout << "0\n";
        }
    }
    
    return 0;
}