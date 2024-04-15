#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    if(n <= 0) {
        cout << 0 << '\n';
        return 0;
    }
    int arr[n];
    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }
    int sum = accumulate(arr, arr+n, 0);
    int f_0 = 0;
    for(int i=0; i<n; i++) {
        f_0 += (i * arr[i]);
    }
    int ans = f_0;
    int f_curr = f_0;
    for(int i=1; i<n; i++) {    
        f_curr = f_curr + sum - (n*arr[n-i]);
        ans = max(ans, f_curr);
    }
    cout << ans << '\n';
}