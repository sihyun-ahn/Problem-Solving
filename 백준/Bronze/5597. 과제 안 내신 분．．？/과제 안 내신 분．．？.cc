#include <iostream>
#include <set>
#include <iterator>
#include <algorithm>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  int n;
  set<int> s1, s2, s_diff;
  for (int i = 1; i <= 30; i++) {
    s2.insert(i);
    if (i > 28)
      continue;
    cin >> n;
    s1.insert(n);
  }

  set_difference(s2.begin(), s2.end(), s1.begin(), s1.end(), inserter(s_diff, s_diff.end()));

  for (set<int>::iterator iter = s_diff.begin(); iter != s_diff.end(); iter++) {
    cout << *iter << '\n';
  }
  return 0;
}