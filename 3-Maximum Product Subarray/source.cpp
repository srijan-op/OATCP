#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    long long n;
    cin>>n;
    if(n <= 0) {
        cout << 0 << '\n';
        return 0;
    }
    long long arr[n];
    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }
    long long max_ending_here = arr[0];
    long long min_ending_here = arr[0];
    long long ans = arr[0];
    for(int i=1; i<n; i++) {
        max_ending_here = max(arr[i], max(max_ending_here * arr[i], min_ending_here * arr[i]));
        min_ending_here = min(arr[i], min(min_ending_here * arr[i], min_ending_here * arr[i]));
        ans = max(ans, max_ending_here%MOD);
    }
    cout << ans << '\n';
}