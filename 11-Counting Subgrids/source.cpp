#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    vector<bitset<64>> all_bits(n);
    for(int i=0; i<n; i++) {
        string bits;
        for(int i=0; i<n; i++) {
            string bit;
            cin>>bit;
            bits += bit;   
        }
        all_bits[i] = bitset<64>(bits);
    }
    int ans = 0;
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            int on_bits = (all_bits[i] & all_bits[j]).count();
            ans += (on_bits * (on_bits-1))/2;
        }
    }
    cout << ans << '\n';
}