#include <bits/stdc++.h>
using namespace std;

void solve() {

    int n;
    cin >> n;

    queue<int> q;

    for (int i = 0; i < n; i++) {

        int x;
        cin >> x;

        q.push(x);
    }

    while (!q.empty()) {

        cout << q.front() << " ";

        q.pop();
    }

    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}