#include <iostream>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, m, cnt = 0;
  string s, target = "";
  cin >> n >> m >> s;
  for (int i=0; i<n; i++) {
    target += "IO";
  }
  target += "I";
  for (int i = 0; i <= s.size() - (2*n + 1); i ++) {
    if (s.substr(i, 2*n + 1) == target) {
      cnt ++;
    }
  }
  cout << cnt;
  return 0;
}