#include <iostream>
#include <vector>
#include <array>
#include <limits>
using namespace std;

#define INF numeric_limits<int>::max()

int heapSize = 0;

void swap(int *dist, int *node, int i, int j) {
  int temp;
  // swap dist
  temp = dist[i];
  dist[i] = dist[j];
  dist[j] = temp;
  // swap node
  temp = node[i];
  node[i] = node[j];
  node[j] = temp;
}

void sink(int *dist, int *node, int i) {
  int j = 2 * i;
  if (j > heapSize) { return; }
  if (j < heapSize && dist[j] > dist[j + 1]) {
    j ++;
  }
  if (dist[i] > dist[j]) {
    swap(dist, node, i, j);
  }
}

void swim(int *dist, int *node, int i) {
  while (i > 1 && dist[i/2] > dist[i]) {
    swap(dist, node, i/2, i);
    i = i/2;
  }
}

void heapify(int *dist, int *node) {
  for (int i = heapSize/2; i > 0; i --) {
    sink(dist, node, i);
  }
}

void deleteMin(int *dist, int *node) {
  dist[1] = dist[heapSize];
  node[1] = node[heapSize];
  heapSize --;
  sink(dist, node, 1);
}

void setValue(int key, int value, int *dist, int *node) {
  for (int i=1; i<=heapSize; i++) {
    if (node[i] == key) {
      dist[i] = value;
      swim(dist, node, i);
    }
  }
}

void dijkstra(int v, int *dist, int *node, int *resDist, vector<vector<array<int, 2>>> edge) {
  int minNode, minDist;
  vector<array<int, 2>>::iterator iter;
  while (heapSize > 0) {
    minNode = node[1];
    minDist = dist[1];
    deleteMin(dist, node);
    for (iter = edge.at(minNode).begin(); iter != edge.at(minNode).end(); iter++) {
      if (minDist != INF && resDist[(*iter)[0]] > minDist + (*iter)[1]) {
        setValue((*iter)[0], minDist + (*iter)[1], dist, node);
        resDist[(*iter)[0]] = minDist + (*iter)[1];
      }
    }
  }
  for (int i=1; i<=v; i++) {
    if (resDist[i] == INF) {
      cout << "INF\n";
    } else {
      cout << resDist[i] << '\n';
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int v, e, k, start, fin, weight;
  cin >> v >> e >> k;
  int *dist = new int[v + 1]();
  int *node = new int[v + 1]();
  int *resDist = new int[v + 1]();
  vector<vector<array<int, 2>>> edge(v + 1);
  heapSize = v;
  for (int i=1; i<=v; i++) {
    vector<array<int, 2>> v;
    dist[i] = INF;
    resDist[i] = INF;
    node[i] = i;
    edge.at(i) = v;
  }
  for (int i=0; i<e; i++) {
    cin >> start >> fin >> weight;
    edge.at(start).push_back({fin, weight});
  }
  resDist[k] = 0;
  dist[k] = 0;
  heapify(dist, node);
  dijkstra(v, dist, node, resDist, edge);

  delete[] dist;
  delete[] node;
  delete[] resDist;
  return 0;
}