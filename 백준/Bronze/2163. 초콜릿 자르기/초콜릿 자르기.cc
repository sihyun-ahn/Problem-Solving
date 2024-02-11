#include <iostream>
using namespace std;

int main() {
  int m, n;
  cin >> m >> n;
  int** count = new int*[m + 1];

  for (int i=0; i<=m; i++) {
    count[i] = new int[n+1]();
    if (i==0)
      continue;
    for (int j=1; j<=n; j++) {
      if (i==1 && j==1) {
        continue;
      }
      count[i][j] = (i > 1) ? count[i/2][j] + count[i - i/2][j] + 1: count[i][j/2] + count[i][j - j/2] + 1;
    }
  }

  cout << count[m][n];

  return 0;
}