#include <bits/stdc++.h>
using namespace std;

string solve(int N, vector<int>& A) {
    map<int, int, greater<int>> counts;
    for (int x : A) {
        counts[x]++;
    }
    long long alex_total = 0;
    long long bob_total = 0;

    for (auto const& [value, freq] : counts) {
        if (freq >= 1) {
            alex_total += value;
        }
        if (freq >= 2) {
            bob_total += value;
        }
    }
    if (alex_total > bob_total) {
        return "Alex";
    } else {
        return "Bob";
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int N;
        cin >> N;
        vector<int> A(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        cout << solve(N, A) << "\n";
    }
    return 0;
}