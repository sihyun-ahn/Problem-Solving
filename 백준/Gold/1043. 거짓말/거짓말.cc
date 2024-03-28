#include <iostream>
using namespace std;

int getParent(int *nodes, int idx) {
  if (nodes[idx] == idx) {
    return idx;
  }
  return getParent(nodes, nodes[idx]);
}

int unionParent(int *nodes, int a, int b) {
  int parentA = getParent(nodes, a);
  int parentB = getParent(nodes, b);
  if (parentA < parentB) {
    nodes[parentB] = parentA;
    nodes[b] = parentA;
    return a;
  } else {
    nodes[parentA] = parentB;
    nodes[a] = parentB;
    return b;
  }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, t, truthNum, partyNum, parent, participant, truth = 0, cnt = 0;
    cin >> n >> m >> t;
    int *nodes = new int[n+1]();
    int *parties = new int[m]();
    for (int i=1; i<=n; i++) {
      nodes[i] = i;
    }
    for (int i=0; i<t; i++) {
      cin >> truthNum;
      if (i == 0) {
        truth = truthNum;
      } else {
        truth = unionParent(nodes, truth, truthNum);
      }
    }
    for (int i=0; i<m; i++) {
      cin >> partyNum;
      for (int j=0; j<partyNum; j++) {
        cin >> participant;
        if (j == 0) {
          parent = participant;
        } else {
          parent = unionParent(nodes, parent, participant);
        }
      }
      parties[i] = parent;
    }
    for (int i=0; i<m; i++) {
      if (getParent(nodes, parties[i]) != getParent(nodes, truth)) {
        cnt ++;
      }
    }
    cout << cnt;
    delete[] parties;
    delete[] nodes;
    return 0;
}