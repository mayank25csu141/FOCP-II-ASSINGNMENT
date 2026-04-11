#include <bits/stdc++.h>
using namespace std;
bool canTurnOff(string &s, int n, int k, int l) {
    int operations = 0;
    for (int i = 0; i < n; ) {
        if (s[i] == '1') {
            operations++;
            if (operations > k) return false;
            i += l; // skip next l bulbs
        } else {
            i++;
        }
    }
    return true;
}
int main() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int low = 1, high = n, ans = n;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (canTurnOff(s, n, k, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    cout << ans << endl;
    return 0;
}