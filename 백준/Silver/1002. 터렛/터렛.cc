#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

struct Coordinate {
  int x;
  int y;
  int r;
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t, cnt;
  double dist;
  Coordinate a, b;
  cin >> t;
  for (int i=0; i<t; i++) {
    cin >> a.x >> a.y >> a.r >> b.x >> b.y >> b.r;
    dist = sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
    if (dist == 0 && a.r == b.r) {
      cnt = -1;
    } else if (abs(a.r - b.r) == dist) { // 내접
      cnt = 1;
    } else if (abs(a.r - b.r) > dist) {
      cnt = 0;
    } else if (dist == a.r + b.r) { // 외접
      cnt = 1;
    } else if (dist > a.r + b.r) {
      cnt = 0;
    } else {
      cnt = 2;
    }
    cout << cnt << '\n';
  }
}
