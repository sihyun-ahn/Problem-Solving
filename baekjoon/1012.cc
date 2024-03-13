#include <iostream>
using namespace std;

int cnt;

void dfs(bool **map, bool **visited, int x, int y, int m, int n) {
  int newX, newY;
  int dx[4] = {1, -1, 0, 0};
  int dy[4] = {0, 0, 1, -1};
  for (int i = 0; i < 4; i++) {
    newX = x + dx[i];
    newY = y + dy[i];
    if (newX >= 0 && newX < m && newY >= 0 && newY < n) {
      if (!visited[newX][newY] && map[newX][newY]) {
          visited[newX][newY] = true;
          dfs(map, visited, newX, newY, m, n);
      }      
    }
  }
  return;
}

void createMap(int m, int n, int k) {
  int x, y;
  cnt = 0;
  bool **map = new bool*[m];
  bool **visited = new bool*[m];
  for (int i=0; i<m; i++) {
    map[i] = new bool[n]();
    visited[i] = new bool[n]();
  }
  for (int i=0; i<k; i++) {
    cin >> x >> y;
    map[x][y] = true;
  }
  for (int i=0; i<m; i++) {
    for (int j=0; j<n; j++) {
      if (!visited[i][j] && map[i][j]) {
        dfs(map, visited, i, j, m, n);
        cnt++;
      }
    }
  }
  for (int i=0; i<m; i++) {
    delete[] map[i];
    delete[] visited[i];
  }
  delete[] map;
  delete[] visited;
  cout << cnt << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t, m, n, k;
  cin >> t;
  for (int i=0; i<t; i++) {
    cin >> m >> n >> k;
    createMap(m, n, k);
  }
  return 0;
}