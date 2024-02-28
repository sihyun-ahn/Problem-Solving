#include <iostream>
#include <cmath>
using namespace std;

struct Coordinate {
  int x;
  int y;
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t, n, cx, cy, r, cnt;
  Coordinate start, end;
  cin >> t;
  for (int i=0; i<t; i++) {
    cnt = 0;
    cin >> start.x >> start.y >> end.x >> end.y >> n;
    for (int j=0; j<n; j++) {
      cin >> cx >> cy >> r;
      if ((pow(cx - start.x, 2) + pow(cy - start.y, 2) <= r*r) ^ (pow(cx - end.x, 2) + pow(cy - end.y, 2) <= r*r)) {
        cnt ++;
      }
    }
    cout << cnt << '\n';
  }
}
