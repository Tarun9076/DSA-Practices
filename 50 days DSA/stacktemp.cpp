#include <bits/stdc++.h>
using namespace std;

void solve() {

    int n;
    cin >> n;

    stack<int> st;

    for (int i = 0; i < n; i++) {

        int x;
        cin >> x;

        st.push(x);
    }

    while (!st.empty()) {

        cout << st.top() << " ";

        st.pop();
    }

    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}