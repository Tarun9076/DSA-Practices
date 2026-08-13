#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
vector<bool> visited;

void dfs(int node) {

    visited[node] = true;

    cout << node << " ";

    for (int next : graph[node]) {

        if (!visited[next]) {
            dfs(next);
        }
    }
}

int main() {

    int n, m;
    cin >> n >> m;

    graph.resize(n + 1);
    visited.resize(n + 1, false);

    for (int i = 0; i < m; i++) {

        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    dfs(1);

    return 0;
}