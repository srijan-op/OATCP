#include<bits/stdc++.h>
using namespace std;

bool checkForEulerianPath(map<int, int> &indegree, map<int, int> &outdegree, set<int> &nodes) {
    bool one = false;
    bool two = false;
    for(auto node : nodes) {
        int ind = indegree.count(node) ? indegree[node] : 0;
        int outd = outdegree.count(node) ? outdegree[node] : 0;
        if(abs(ind - outd) > 1) {
            return false;
        }
        if(ind - outd == 1) {
            if(one) return false;
            else one = true;
        }
        if(outd - ind == 1) {
            if(two) return false;
            else two = true;
        }
    }
    return true;
}

int getPathStart(map<int, int> &indegree, map<int, int> &outdegree, set<int> &nodes) {
    for(auto node: nodes) {
        int ind = indegree.count(node) ? indegree[node] : 0;
        int outd = outdegree.count(node) ? outdegree[node] : 0;
        if(outd-ind == 1) {
            return node;
        }
    }
    return *nodes.begin();
}

void dfs(int startNode, stack<int> &st, map<int, vector<int>> &graph) {
    while(graph[startNode].size()) {
        int adjNode = graph[startNode].back();
        graph[startNode].pop_back();
        dfs(adjNode, st, graph);
    }
    st.push(startNode);
}

vector<int> getEulerianPath(map<int, int> &indegree, map<int, int> &outdegree, set<int> &nodes, map<int, vector<int>> &graph) {
    int startNode = getPathStart(indegree, outdegree, nodes);
    stack<int> st;
    dfs(startNode, st, graph);
    vector<int> path;
    while(!st.empty()) {
        int node = st.top();
        st.pop();
        path.push_back(node);
    }
    return path;
}

int main() {
    int n;
    cin>>n;
    map<int, vector<int>> graph;
    map<int, int> indegree;
    map<int, int> outdegree;
    set<int> nodes;
    for(int i=0; i<n; i++) {
        int x, y;
        cin>>x>>y;
        graph[x].push_back(y);
        indegree[y] += 1;
        outdegree[x] += 1;
        nodes.insert(x);
        nodes.insert(y);
    }
    if(!checkForEulerianPath(indegree, outdegree, nodes)) {
        cout << -1 << '\n';
        return 0;
    }
    vector<int> path = getEulerianPath(indegree, outdegree, nodes, graph); 
    for(int i=0; i<path.size()-1; i++) {
        cout << path[i] << ' '<< path[i+1] << '\n';
    }
}