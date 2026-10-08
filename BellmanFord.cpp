#include <bits/stdc++.h>
using namespace std;

int main() {
    int v, e;
    cin >> v >> e;

    vector<vector<pair<int,int>>> adj(v);

    for(int i = 0; i < e; i++) {
        int x, y, w;
        cin >> x >> y >> w;

        adj[x].push_back({y, w});
    }

    vector<int> dist(v, 999999);
    dist[0] = 0;

    for(int i = 0; i < v - 1; i++) {
        for(int u = 0; u < v; u++) {
            for(auto [to, w] : adj[u]) {

                if(dist[u] + w < dist[to]) {
                    dist[to] = dist[u] + w;
                }
            }
        }
    }

    for(int u = 0; u < v; u++) {
        for(auto [to, w] : adj[u]) {
            if(dist[u] + w < dist[to]) {
                cout << "Negative cycle detected";
                return 0;
            }
        }
    }

    for(int x : dist) cout << x << " ";
}
