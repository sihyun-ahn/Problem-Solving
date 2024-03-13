#include <iostream>
#include <stack>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  string ps;
  bool vps = true;
  stack<char> s;
  cin >> n;
  for (int i=0; i<n; i++) {
    cin >> ps;
    vps = true;
    for (int j=0; j<ps.size(); j++) {
      if (ps[j] == '(') {
        s.push(ps[j]);
      } else {
        if (s.empty()) {
          vps = false;
          break;
        } else {
          s.pop();
        }
      }
    }
    if (!vps || !s.empty()) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
    }
    while (!s.empty()) {
      s.pop();
    }
  }
  
  return 0;
}