#include<bits/stdc++.h>
using namespace std;

bool getAugmentedPath(int src, int dest, vector<int> &parent, vector<vector<int>> &residualGraph) {
    vector<bool> vis(residualGraph.size(), false);
    vis[src] = 1;
    parent[src] = -1;
    queue<int> q;
    q.push(src);
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        for(int i=0; i<residualGraph[node].size(); i++) {
            int adjNode = i;
            int residual = residualGraph[node][adjNode];
            if(!vis[adjNode] && residual > 0) {
                parent[adjNode] = node;
                vis[adjNode] = 1;
                q.push(adjNode);
                if(adjNode == dest) {
                    return true;
                }
            }
        }
    }
    return false;
}

int getMaximumFlow(int src, int dest, vector<vector<int>> &graph) {
    vector<int> parent(graph.size());
    vector<vector<int>> residualGraph = graph;
    int max_flow = 0;
    while(getAugmentedPath(src, dest, parent, residualGraph)) {
        int node = dest;
        int bottleneck = INT_MAX;
        while(parent[node] != -1) {
            bottleneck = min(residualGraph[parent[node]][node], bottleneck);
            node = parent[node];
        }
        node = dest;
        while(parent[node] != -1) {
            residualGraph[parent[node]][node] -= bottleneck;
            residualGraph[node][parent[node]] += bottleneck;
            node = parent[node];
        }
        max_flow += bottleneck;
    }
    return max_flow;
}

int main() {
    int n;
    cin>>n;
    vector<vector<int>> graph(n+1, vector<int>(n+1, 0));
    int src, dest;
    cin>>src>>dest;
    int m;
    cin>>m;
    for(int i=0; i<m; i++) {
        int x, y, w;
        cin>>x>>y>>w;
        graph[x][y] = w;
    }
    int ans = getMaximumFlow(src, dest, graph);
    cout << ans << '\n';
}
