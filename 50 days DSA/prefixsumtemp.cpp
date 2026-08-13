#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {

    int n;
    cin >> n;

    vector<ll> a(n);
    vector<ll> prefix(n + 1, 0);

    for (int i = 0; i < n; i++) {
        cin >> a[i];

        prefix[i + 1] = prefix[i] + a[i];
    }

    // Sum from index l to r:
    // prefix[r + 1] - prefix[l]

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}