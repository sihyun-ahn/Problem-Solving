#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
using namespace std;

bool sortByFin(array<int, 2> a, array<int, 2> b) {
  if (a[1] < b[1]) {
    return true;
  } else if (a[1] == b[1]) {
    return (a[0] < b[0]);
  } else {
    return false;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, start, fin, cnt = 0;
  vector<array<int, 2>> v;
  cin >> n;
  for (int i=0; i<n; i++) {
    cin >> start >> fin;
    v.push_back({start, fin});
  }
  sort(v.begin(), v.end(), sortByFin);

  fin = 0;
  for (vector<array<int, 2>>::iterator iter = v.begin(); iter != v.end(); iter ++) {
    if ((*iter)[0] >= fin) {
      cnt ++;
      fin = (*iter)[1];
    }
  }
  cout << cnt;
  return 0;
}