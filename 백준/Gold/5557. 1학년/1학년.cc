#include <iostream>
using namespace std;

void setDp(int *operands, long long **dp, int n) {
  int tempAdd, tempSub;
  dp[0][operands[0]]++;
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < 21; j++) {
      if (dp[i-1][j] > 0) {
        tempAdd = j + operands[i];
        tempSub = j - operands[i];
        if (tempAdd >= 0 && tempAdd <= 20) {
          dp[i][tempAdd] += dp[i-1][j];
        }
        if (tempSub >= 0 && tempSub <= 20) {
          dp[i][tempSub] += dp[i-1][j];
        }
      }
    }
  }
}


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, result;
  bool isValid;
  cin >> n;
  int *operands = new int[n - 1]();
  long long **dp = new long long*[n - 1]();

  for (int i = 0; i < n - 1; i++) {
    dp[i] = new long long[21]();
    cin >> operands[i];
  }
  cin >> result;

  setDp(operands, dp, n-1);
  cout << dp[n-2][result];

  for (int i = 0; i < n - 1; i++) {
    delete[] dp[i];
  }
  delete[] operands;
  delete[] dp;
  return 0;
}
