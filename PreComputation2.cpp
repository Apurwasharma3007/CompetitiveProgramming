//Prefix Sum in 2D array
#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
int ar[N][N];
long long pf[N][N];

int main() {
    int n;
    cin >> n;

    // Input the 2D array
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> ar[i][j];
            // Compute the prefix sum
            pf[i][j] = ar[i][j] + pf[i-1][j] + pf[i][j-1] - pf[i-1][j-1];
        }
    }

    int q;
    cin >> q;
    while (q--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        // Calculate the submatrix sum
        long long result = pf[c][d] - pf[a-1][d] - pf[c][b-1] + pf[a-1][b-1];
        cout << result << endl;
    }

    return 0;
}

