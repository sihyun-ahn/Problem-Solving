#include <iostream>
#include <set>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, m;
  string input;
  set<string> s1, s2, s;
  cin >> n >> m;
  for (int i=0; i<n; i++) {
    cin >> input;
    s1.insert(input);
  }
  for (int i=0; i<m; i++) {
    cin >> input;
    s2.insert(input);
  }
  if (n <= m) {
    for (set<string>::iterator iter = s1.begin(); iter != s1.end(); iter ++) {
      if (s2.find(*iter) != s2.end()) {
        s.insert(*iter);
      }
    }
  } else {
    for (set<string>::iterator iter = s2.begin(); iter != s2.end(); iter ++) {
      if (s1.find(*iter) != s1.end()) {
        s.insert(*iter);
      }
    }
  }

  cout << s.size() << '\n';
  for (set<string>::iterator iter = s.begin(); iter != s.end(); iter ++) {
    cout << *iter << '\n';
  }

  return 0;
}