#include <bits/stdc++.h>
using namespace std;

void solve() {

    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n + 1);

    for (int i = 0; i < m; i++) {

        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<bool> visited(n + 1, false);

    queue<int> q;

    int start = 1;

    q.push(start);
    visited[start] = true;

    while (!q.empty()) {

        int node = q.front();
        q.pop();

        cout << node << " ";

        for (int next : graph[node]) {

            if (!visited[next]) {

                visited[next] = true;
                q.push(next);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}