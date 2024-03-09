#include <iostream>
#include <vector>
#include <array>
#include <map>
#include <algorithm>
using namespace std;

bool cmp(array<int, 3> a, array<int, 3> b) {
  return a[2] < b[2];
}

int findParent(int *vertex, int target) {
  if (target == vertex[target]) {
    return target;
  }
  vertex[target] = findParent(vertex, vertex[target]);
  return vertex[target];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int v, e, es, ef, ev, parent1, parent2, parentNode, childNode, cnt = 0;
  vector<array<int, 3>>::iterator iter;
  vector<array<int, 3>> edge;
  cin >> v >> e;
  int *vertex = new int[v + 1]();

  for (int i=1; i<=v; i++) {
    vertex[i] = i;
  }
  for (int i=0; i<e; i++) {
    cin >> es >> ef >> ev;
    edge.push_back({es, ef, ev});
  }

  sort(edge.begin(), edge.end(), cmp);

  for (iter = edge.begin(); iter != edge.end(); iter ++) {
    parent1 = findParent(vertex, (*iter)[0]);
    parent2 = findParent(vertex, (*iter)[1]);
    if (parent1 != parent2) {
      if (parent1 < parent2) {
        vertex[parent2] = parent1;
      } else {
        vertex[parent1] = parent2;
      }
      cnt += (*iter)[2];
    }
  }
  cout << cnt;

  delete[] vertex;
  return 0;
}