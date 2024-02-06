#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  int n, m, cnt;
  cin >> n >> m;
  int** rooms = new int*[n];
  for (int i=0; i<n; i++) {
    rooms[i] = new int[m];
    for (int j=0; j<m; j++) {
      cin >> rooms[i][j];
    }
  }

  for (int i=0; i<n; i++) {
    for (int j=0; j<m; j++) {
      if (i != 0 || j != 0) {
        if (i == 0)
          rooms[i][j] += rooms[i][j-1];
        else if (j ==0)
          rooms[i][j] += rooms[i-1][j];
        else {
          rooms[i][j] += max({rooms[i-1][j-1], rooms[i-1][j], rooms[i][j-1]});
        }
      }
    }
  }

  cout << rooms[n-1][m-1];

  delete[] rooms;
  return 0;
}