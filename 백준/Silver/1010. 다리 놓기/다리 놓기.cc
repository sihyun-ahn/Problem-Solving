#include <iostream>
#include <set>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t, n, m, res;
  cin >> t;
  for (int i=0; i<t; i++) {
    cin >> n >> m;
    res = 1; // mCn
    for (int j=1; j<=n; j++) {
      res *= m - j + 1;
      res /= j;
    }
    cout << res << '\n';
  }
  return 0;
}