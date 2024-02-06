#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  int n, cur, cnt = -1;
  cin >> n;
  int* rooms = new int[n];
  int* idx = new int[n];
  for (int i=0; i<n; i++) {
    cin >> rooms[i];
    idx[i] = -1;
  }

  for (int i=0; i<n; i++) {
    if (idx[i] != -1 || i == 0) {
      for (int j=1; j<=min({rooms[i], n-i-1}); j++) {
        if (idx[i + j] == -1)
          idx[i + j] = i;
        else
          idx[i + j] = min(i, idx[i + j]);
      }
    }
  }

  cur = idx[n - 1];
  if (cur != -1 || n == 1) {
    cnt ++;
  }

  while (cur != -1) {
    cur = idx[cur];
    cnt ++;
  }

  cout << cnt;

  delete[] rooms;
  delete[] idx;
  return 0;
}