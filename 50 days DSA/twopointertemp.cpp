#include <bits/stdc++.h>
using namespace std;

void solve() {

    int n;
    cin >> n;

    vector<int> a(n);

    for (int &x : a) {
        cin >> x;
    }

    int left = 0;
    int right = n - 1;

    while (left < right) {

        // Your condition

        if (/* condition */) {
            left++;
        }
        else {
            right--;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}