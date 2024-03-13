#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
using namespace std;

bool cmp(array<int, 2> a, array<int, 2> b) {
  return a[0] < b[0];
}

void recruit(vector<array<int, 2>> v) {
  vector<array<int, 2>>::iterator outer, inner;
  int min = v.size() + 1, cnt = 0;
  sort(v.begin(), v.end(), cmp);
  for (outer = v.begin(); outer != v.end(); outer ++) {
    if ((*outer)[1] < min) {
      min = (*outer)[1];
      cnt ++;
    }
  }
  cout << cnt << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t, n, r1, r2;
  cin >> t;
  for (int i=0; i<t; i++) {
    cin >> n;
    vector<array<int, 2>> v;
    for (int j=0; j<n; j++) {
      cin >> r1 >> r2;
      v.push_back({r1, r2});
    }
    recruit(v);
  }

  return 0;
}