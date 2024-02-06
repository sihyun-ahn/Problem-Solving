#include <iostream>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, m, s, e;
  cin >> n;
  int* num = new int[n + 1]();
  int** dp = new int*[n + 1];
  for (int i=1; i<=n; i++) {
    cin >> num[i];
    dp[i] = new int[n + 1]();
    for (int j=1; j<=i; j++) {
      if (j + 1 <= i - 1)
        dp[j][i] = (num[j] == num[i]) ? dp[j + 1][i - 1] : 0;
      else
        dp[j][i] = (num[j] == num[i]) ? 1 : 0;
    }
  }

  cin >> m;
  int* ans = new int[m];
  for (int i=0; i<m; i++) {
    cin >> s >> e;
    ans[i] = dp[s][e];
  }

  for (int i=0; i<m; i++) {
    cout << ans[i] << '\n';
  }

  delete[] num;
  delete[] dp;
  delete[] ans;

  return 0;
}