#include <bits/stdc++.h>

using namespace std;

const int MX = 3e5 + 20;
int n;
string strings[MX];
map<string, int> string_to_id;
map<int, string> id_to_string;
vector<int> adjList[MX];

void buildGraph(int curr, int index, string &currSubstring, string substring) {
    if(substring.size() > 4) return;

    if(!substring.empty()) {
        if (string_to_id.find(substring) == string_to_id.end()) {
            string_to_id[substring] = string_to_id.size() + 1;
            id_to_string[string_to_id[substring]] = substring;
        }
        adjList[curr].push_back(string_to_id[substring] + n);
    }
    if(index == currSubstring.size())
        return;
    buildGraph(curr, index + 1, currSubstring, substring);
    buildGraph(curr, index + 1, currSubstring, substring + currSubstring[index]);
}

int reachingNode[MX], resNode[MX], vis[MX];

bool check(int node) {
    if(vis[node]) return false;
    vis[node] = true;
    for(auto child : adjList[node]) {
        if (reachingNode[child] == 0 || check(reachingNode[child])) {
            reachingNode[child] = node;
            resNode[node] = child;
            return true;
        }
    }
    return false;
}

int main() {
    cin >> n;
    for(int i=1; i<=n; i++) {
        cin>>strings[i];
        string substring;
        buildGraph(i, 0, strings[i], substring);
    }
    int count = 0;
    for(int i=1; i<=n; i++) {
        memset(vis, 0, sizeof vis);
        count += check(i);
    }
    if(count == n) {
        for (int i=1; i<=n; i++) {
            cout << id_to_string[resNode[i] - n] << '\n';
        }
    }
    else cout << -1 << '\n';
}