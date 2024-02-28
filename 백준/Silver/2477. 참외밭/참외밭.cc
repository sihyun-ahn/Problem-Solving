#include <iostream>
#include <algorithm>
using namespace std;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int k, d, s, x1 = 0, x2 = 0, y1 = 0, y2 = 0;
  int path[6][2];
  cin >> k;
  for (int i=0; i<6; i++) {
    cin >> d >> s;
    path[i][0] = d;
    path[i][1] = s;
  }
  for (int i=0; i<6; i++) {
    int former = (i == 0) ? 5 : i - 1;
    int later = (i == 5) ? 0 : i + 1;
    if (path[i][0] == 1 || path[i][0] == 2) {
      if (path[former][0] == path[later][0]) {
        x2 = path[i][1];
      } else {
        x1 = max({x1, path[i][1]});
      }
    } else {
      if (path[former][0] == path[later][0]) {
        y2 = path[i][1];
      } else {
        y1 = max({y1, path[i][1]});
      }
    }
  }
  cout << k * (x1 * y1 - x2 * y2);
}
