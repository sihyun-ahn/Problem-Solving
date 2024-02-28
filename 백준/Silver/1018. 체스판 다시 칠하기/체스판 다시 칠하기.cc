#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, m, cnt, outputW = -1, outputB = -1;
  char c;
  cin >> n >> m;
  char **map = new char*[n];
  for (int i = 0; i < n; i++) {
    map[i] = new char[m];
    for (int j = 0; j < m; j++) {
      cin >> map[i][j];
    }
  }

  // start with W
  for (int i=0; i<=n-8; i++) {
    for (int j=0; j<=m-8; j++) {
      cnt = 0;
      for (int k=i; k<i+8; k++) {
        for (int l=j; l<j+8; l++) {
          if ((k+l) % 2 == 0 && map[k][l] == 'B') {
            cnt ++;
          } else if ((k+l) % 2 == 1 && map[k][l] == 'W') {
            cnt ++;           
          }
        }
      }
      outputW = (outputW == -1) ? cnt : min({outputW, cnt});
    }
  }

  // start with B
  for (int i=0; i<=n-8; i++) {
    for (int j=0; j<=m-8; j++) {
      cnt = 0;
      for (int k=i; k<i+8; k++) {
        for (int l=j; l<j+8; l++) {
          if ((k+l) % 2 == 0 && map[k][l] == 'W') {
            cnt ++;
          } else if ((k+l) % 2 == 1 && map[k][l] == 'B') {
            cnt ++;           
          }
        }
      }
      outputB = (outputB == -1) ? cnt : min({outputB, cnt});
    }
  }

  cout << min({outputW, outputB});

  for (int i = 0; i < n; i++) {
    delete[] map[i];
  }
  delete[] map;
  return 0;
}