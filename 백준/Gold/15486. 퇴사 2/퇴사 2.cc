#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Consult {
  int t;
  int p;
};

int main() {
  int n;
  cin >> n;
  Consult* plans = new Consult[n];
  int* dp = new int[n + 1]();

  // init plans
  for (int i = 0; i < n; i++) {
    cin >> plans[i].t >> plans[i].p;
  }

  // DP
  for (int i = n-1; i >= 0; i--) {
    // if cousult cannot be done in N days
    if (i + plans[i].t > n) {
      dp[i] = dp[i + 1];
      continue;
    }
    // if consult is done at N-th day
    // if (i + plans[i].t == n) {
    //   dp[i] = max({plans[i].p, dp[i + 1]});
    // }
    else {
      dp[i] = max({plans[i].p + dp[i + plans[i].t], dp[i + 1]});
    }
  }
  
  std::cout << dp[0];

  delete[] plans;
  delete[] dp;
  return 0;
}