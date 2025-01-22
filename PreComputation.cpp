//Prefix Sum in 1D array
#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    int a[n], prefixSum[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    prefixSum[0] = a[0];
    for (int i = 1; i < n; i++) {
        prefixSum[i] = prefixSum[i - 1] + a[i];
    }
    for (int i = 0; i < n; i++) {
        cout << prefixSum[i] << " ";
    }

    return 0;
}


























