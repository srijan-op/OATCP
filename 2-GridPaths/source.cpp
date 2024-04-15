#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int n;
    cin>>n;
    vector<vector<char>> matrix(n, vector<char>(n));
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin>>matrix[i][j];
        }
    } 
    vector<vector<int>> matrix_dp(n, vector<int>(n, 0));
    matrix_dp[0][0] = 1;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(matrix[i][j] != '*') {
                if(i-1 >= 0) {
                    matrix_dp[i][j] = (matrix_dp[i][j]%MOD + matrix_dp[i-1][j]%MOD)%MOD;
                }
                if(j-1 >= 0) {
                    matrix_dp[i][j] = (matrix_dp[i][j]%MOD + matrix_dp[i][j-1]%MOD)%MOD;
                }
            }
        }
    }
    cout << matrix_dp[n-1][n-1];
}