#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int total_inputs;
    cin>>total_inputs;
    while(total_inputs--) {
        int sum;
        cin>>sum;
        if(sum < 0) {
            cout << 0 << '\n';
            continue;
        } 
        int dp[sum + 1] = {0};
        dp[0] = 1;
        for(int i=1; i<=sum; i++) {
            for(int j=i-1; j>=0 && j>=i-6; j--) {
                dp[i] = (dp[i]%MOD + dp[j]%MOD)%MOD;
            }
        }
        cout << dp[sum] << '\n';
    }
}