#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n, k, c, out = 0;
    cin >> n >> k;
    vector<int> coins;
    vector<int> dp(k+1);
    for (int i=0; i<n; i++) {
        cin >> c;
        coins.push_back(c);
    }
    dp.at(0) = 1;
    sort(coins.begin(), coins.end());
    for (int i=0; i<n; i++) {
        for (int j=1; j<=k; j++) {
            if (coins[i] <= j) {
                dp[j] += dp[j - coins[i]];
            }
        }
    }
    
    cout << dp[k];

    return 0;
}
