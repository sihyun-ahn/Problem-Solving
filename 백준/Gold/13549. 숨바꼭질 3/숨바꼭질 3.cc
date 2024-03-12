#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

void dijkstra(int *count, int n, int k) {
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  for (int i=0; i<=100000; i++) {
    count[i] = 100000;
  }
  pair<int, int> min;
  int minNode, minDist;
  pq.push(make_pair(0, n));
  while (!pq.empty()) {
    min = pq.top();
    minNode = min.second;
    minDist = min.first;
    pq.pop();
    if (minDist < count[minNode]) {
      count[minNode] = minDist;
      if (minNode + 1 >= 0 && minNode + 1 <= 100000 && count[minNode + 1] > minDist + 1) {
        pq.push(make_pair(minDist + 1, minNode + 1));
      }
      if (minNode - 1 >= 0 && minNode - 1 <= 100000 && count[minNode - 1] > minDist + 1) {
        pq.push(make_pair(minDist + 1, minNode - 1));
      }
      if (minNode * 2 >= 0 && minNode * 2 <= 100000 && count[minNode * 2] > minDist) {
        pq.push(make_pair(minDist, minNode * 2));
      }
    }
  }
  cout << count[k];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, k;
  cin >> n >> k;
  int *count = new int[100001]();
  dijkstra(count, n, k);
  delete[] count;
  return 0;
}