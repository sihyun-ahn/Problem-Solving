#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, temp;
    cin >> n;
    int *dp = new int[n + 1]();
    for (int i=2; i<= n; i++) {
      temp = dp[i - 1];
      if (i % 2 == 0) {
        temp = min({dp[i / 2], dp[i - 1]});
      }
      if (i % 3 == 0) {
        temp = min({dp[i / 3], temp});
      }
      dp[i] = temp + 1;
    }
    cout << dp[n];
    return 0;
}