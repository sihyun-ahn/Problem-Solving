#include <iostream>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, m, res = 0, cnt = 0;
  char s;
  bool counting = false, nextI = true;
  cin >> n >> m;

  for (int i = 0; i < m; i ++) {
    cin >> s;
    if (counting) {
      if (nextI) {
        if (s == 'I') {
          cnt ++;
          nextI = false;
        } else {
          cnt --;
          res += (cnt - n + 1 > 0) ? cnt - n + 1 : 0;
          counting = false;
        }
      } else {
        if (s == 'O') {
          nextI = true;          
        } else {
          cnt --;
          res += (cnt - n + 1> 0) ? cnt - n + 1 : 0;

          counting = true;
          nextI = false;
          cnt = 1;
        }
      }
    } else {
      if (nextI && s == 'I') {
        counting = true;
        cnt = 1;
        nextI = false;
      } else {
        nextI = true;
        cnt = 0;
      }
    }
  }

  if (counting) {
    cnt --;
    res += (cnt - n + 1> 0) ? cnt - n + 1 : 0;
  }

  cout << res;
  return 0;
}