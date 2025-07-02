#include <iostream>
#include <vector>
using namespace std;

int main() {
  int t, n;
  cin >> t;

  int *dp = new int[11]();
  dp[1] = 1;
  dp[2] = 2;
  dp[3] = 4;
  for (int i=4; i<=10; i++) {
    dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
  }

  for (int i=0; i<t; i++) {
    cin >> n;
    cout << dp[n];
    if (i != t-1) cout << '\n';
  }

  return 0;
}