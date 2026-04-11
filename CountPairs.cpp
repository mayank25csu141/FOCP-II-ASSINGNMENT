#include <bits/stdc++.h>
using namespace std;
const int MAX = 1000000;
vector<int> primes;
void sieve() {
    vector<bool> isPrime(MAX, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i < MAX; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
            for (long long j = 1LL * i * i; j < MAX; j += i)
                isPrime[j] = false;
        }
    }
}
int countDistinctPrimes(long long n) {
    int count = 0;
    for (int p : primes) {
        if (1LL * p * p > n) break;
        if (n % p == 0) {
            count++;
            while (n % p == 0)
                n /= p;
        }
    }
    if (n > 1) count++; // remaining prime
    return count;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    sieve();
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        int k = countDistinctPrimes(n);
        cout << (1LL << k) << "\n";
    }
    return 0;
}