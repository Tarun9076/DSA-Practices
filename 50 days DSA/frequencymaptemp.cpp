#include <bits/stdc++.h>
using namespace std;

void solve() {

    int n;
    cin >> n;

    unordered_map<int, int> freq;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        freq[x]++;
    }

    // Example:
    // if (freq[x] > 0)
    //     x exists

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}