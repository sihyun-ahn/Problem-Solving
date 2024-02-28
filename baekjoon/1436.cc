#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, res, idx = 0;
  cin >> n;
  int dp[10000];

  // 3-digit
  dp[idx++] = 666;

  // 4-digit
  for (int i=1; i<=5; i++) {
    if (idx >= n) break;
    dp[idx++] = i*1000 + 666;
  }
  dp[idx++] = 6660;
  for (int i=6; i<=9; i++) {
    if (idx >= n) break;
    dp[idx++] = 6660 + i;
  }

  // 5-digit
  for (int i=10; i<=65; i++) {
    if (idx >= n) break;
    if (i % 10 == 6) {
      for (int j=0; j<=9; j++) {
        if (idx >= n) break;
        dp[idx++] = (i/10) * 10000 + 6660 + j;
      }
    } else {
      dp[idx++] = i*1000 + 666;
    }
  }
  for (int i=0; i<=99; i++) {
    if (idx >= n) break;
    dp[idx++] = 66600 + i;
  }
  for (int i=67; i<=99; i++) {
    if (idx >= n) break;
    if (i % 10 == 6) {
      for (int j=0; j<=9; j++) {
        if (idx >= n) break;
        dp[idx++] = (i/10) * 10000 + 6660 + j;
      }
    } else {
      dp[idx++] = i*1000 + 666;
    }  }

  // 6-digit
  for (int i=100; i<=665; i++) {
    if (idx >= n) break;
    if (i%100 == 6) {
      if ((i%10 - i%100) == 6) {
        for (int j=0; j<=99; j++) {
          if (idx >= n) break;
          dp[idx++] = i*1000 + 600 + j;
        }
      } else {
        for (int j=0; j<=9; j++) {
          if (idx >= n) break;
          dp[idx++] = i*1000 + 660 + j;
        }
      }
    } else {
      dp[idx++] = i*1000 + 666;
    }
  }
  for (int i=0; i<=999; i++) {
    if (idx >= n) break;
    dp[idx++] = 666000 + i;
  }
  for (int i=667; i<=999; i++) {
    if (idx >= n) break;
    dp[idx++] = i*1000 + 666;
  }

  cout << dp[n-1];
  return 0;
}