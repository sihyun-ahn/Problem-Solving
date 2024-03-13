#include <iostream>
#include <algorithm>
using namespace std;

int findParent(int *map, int node) {
  if (map[node] == node) {
    return node;
  }
  map[node] = findParent(map, map[node]);
  return map[node];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, m, method, a, b, aParent, bParent;
  cin >> n >> m;
  int *map = new int[n + 1]();
  for (int i = 0; i <= n; i ++) {
    map[i] = i;
  }

  for (int i = 0; i < m; i ++) {
    cin >> method >> a >> b;
    if (method == 0) {
      if (a != b) { 
        aParent = findParent(map, a);
        bParent = findParent(map, b);
        if (aParent < bParent) {
          map[bParent] = aParent;
        } else {
          map[aParent] = map[bParent];
        }
      }
    } else {
      if (a == b || findParent(map, a) == findParent(map, b)) {
        cout << "YES\n";
      } else {
        cout << "NO\n";
      }
    }
  }
  delete[] map;
}
