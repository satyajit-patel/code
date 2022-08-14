
#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vii vector<vector<int>>
#define endl "\n"

int n;
vector<pair<int, int>> adj[100005];
void bellmanFord() {
    vi dist(n+1, INT_MAX);
    dist[1] = 0;
    for(int i=1; i<=n-1; i++) {
        for(auto &it:adj[i]) {
            int v = it.first;
            int w = it.second;
            if(dist[i] + w < dist[v]) dist[v] = dist[i] + w;
        }
    }
    //iterate again to check for negative cycle
    for(int i=1; i<=n-1; i++) {
        for(auto &it:adj[i]) {
            int v = it.first;
            int w = it.second;
            if(dist[i] + w < dist[v]) {
                cout<<"there exist a negative cycle\n";
                return;
            }
        }
    }
    for(int i=1; i<=n; i++) cout<<dist[i]<<" ";
}
void graphInput() {
    int m; cin>>n>>m;
    for(int i=0; i<m; i++) {
        int u,v,w; cin>>u>>v>>w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    bellmanFord();
}
int main() {
    graphInput();
    return 0;
}