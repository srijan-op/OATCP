#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    if(n == 0) {
        cout << 0 << '\n';
        return 0;
    }
    int arr[n];
    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }
    int coins;
    cin>>coins;
    sort(arr, arr+n);
    int ans = 0;
    for(int i=0; i<n; i++) {
        if(coins >= arr[i]) {
            coins -= arr[i];
            ans += 1;
        }
        else break;
    }
    cout << ans << '\n';
}