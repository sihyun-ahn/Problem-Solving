#include <iostream>
#include <cmath>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int m, n, mul;
  cin >> m >> n;
  bool *visited = new bool[n + 1]();
  visited[1] = true;
  for (int i=2; i<=sqrt(n); i++) {
    if (!visited[i]) {
      mul = 2;
      while (mul * i <= n) {
        visited[mul * i] = true;
        mul ++;
      }
    }
  }
  for (int i=m; i<=n; i++) {
    if (!visited[i]) {
      cout << i << '\n';
    }
  }
  delete[] visited;
  return 0;
}