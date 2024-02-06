#include <iostream>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  int dp[100001][3];
  dp[0][0] = 0;
  dp[0][1] = 0;
  dp[0][2] = 0;

  for (int i = 1; i <= 10000; i++) {
    if (i - 3 >= 0) {
      dp[i][2] = dp[i - 3][2] + dp[i - 3][1] + 1;
    }
    if (i - 2 >= 0) {
      dp[i][1] = dp[i - 2][1] + 1;
    }
    dp[i][0] = 1; 
  }
  cin >> n;
  int* test = new int[n];
  for (int i=0; i < n; i++) {
    cin >> test[i];
  }
  for (int i=0; i < n; i++) {
    cout << dp[test[i]][0] + dp[test[i]][1] + dp[test[i]][2] << '\n';
  }
  delete[] test;
  return 0;
}