#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7, INF = 1e9;
int main(){
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); 
    }
    vector<int> d(n + 1, INF), w(n + 1, 0);
    queue<int> q;
    d[1] = 0;
    w[1] = 1;
    q.push(1);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v: adj[u]) {
            // Nếu tìm thấy đường đi ngắn hơn đến v
            if (d[v] > d[u] + 1) {
                d[v] = d[u] + 1;
                w[v] = w[u];
                q.push(v);
            } else if (d[v] == d[u] + 1) w[v] = (w[v] + w[u]) % MOD;
        }
    }
    cout << w[n];
}
