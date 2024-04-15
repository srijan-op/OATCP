#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

vector<vector<int>> dp(105, vector<int>(105, -1));

int solve(int i, int j, vector<int> &boys, vector<int> &girls) {
    if(i == boys.size()) {
        return 0;
    }
    if(j == girls.size()) {
        return 0;
    }
    if(dp[i][j] != -1) {
        return dp[i][j];
    }
    int op1 = (abs(boys[i] - girls[j]) <= 1) ? (1%MOD + solve(i+1, j+1, boys, girls)%MOD)%MOD : 0;
    int op2 = solve(i, j+1, boys, girls);
    int op3 = solve(i+1, j, boys, girls);
    return dp[i][j] = max(op1, max(op2, op3));
}

int main() {
    int n;
    cin>>n;
    vector<int> boys(n);
    for(int i=0; i<n; i++) {
        cin>>boys[i];
    }
    int m;
    cin>>m;
    if(n <= 0) {
        cout << 0 << '\n';
        return 0;
    }
    if(m <= 0) {
        cout << 0 << '\n';
        return 0;
    }
    vector<int> girls(m);
    for(int i=0; i<m; i++) {
        cin>>girls[i];
    }
    sort(boys.begin(), boys.end());
    sort(girls.begin(), girls.end());
    cout << solve(0, 0, boys, girls);
}
