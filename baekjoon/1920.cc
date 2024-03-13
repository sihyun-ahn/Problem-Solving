#include <iostream>
#include <set>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, m, arr;
  set<int> s;
  cin >> n;
  for (int i=0; i<n; i++) {
    cin >> arr;
    s.insert(arr);
  }
  cin >> m;
  for (int i=0; i<m; i++) {
    cin >> arr;
    if (s.find(arr) != s.end()) {
      cout << "1\n";
    } else {
      cout << "0\n";
    }
  }

  return 0;
}