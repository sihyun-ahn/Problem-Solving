#include <iostream>
#include <set>
#include <cmath>
using namespace std;

long cnt = 0;

void setDp(vector<vector<int>>& dp, int *operands, int i, int j, int n, int result) {
    int sum = (j == 0) ? operands[0] : dp[i / 2 - 1][j - 1];
    cout << i << " " << j << '\n';
    if (i % 2 == 0) {
        sum -= operands[j + 1];
    } else {
        sum += operands[j + 1];
    }
    if (j >= n - 3) {
        if (sum == result) {
            cnt++;
            dp[i][j] = sum;
        } else {
            dp[i][j] = -1;
        }
        return;
    }

    if (sum < 0 || sum > 20) {
        dp[i][j] = -1;
        return;
    }
    dp[i][j] = sum;
    dp[2 * (i + 1) + 0][j + 1] = sum - operands[j + 2];
    dp[2 * (i + 1) + 1][j + 1] = sum + operands[j + 2];

    setDp(dp, operands, 2 * (i + 1), j + 1, n, result);
    setDp(dp, operands, 2 * (i + 1) + 1, j + 1, n, result);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, result;
  bool isValid;
  cin >> n;
  int *operands = new int[n - 1]();
    vector<vector<int>> dp((1LL << (n - 1)) - 2, vector<int>(n - 2, -1));

  for (int i = 0; i < n - 1; i++) {
      cin >> operands[i];
  }
  cin >> result;

  cout << "\ninitialized operands\n";

  setDp(dp, operands, 0, 0, n, result);
  setDp(dp, operands, 1, 0, n, result);

  cout << cnt;

  delete[] operands;

  return 0;
}
