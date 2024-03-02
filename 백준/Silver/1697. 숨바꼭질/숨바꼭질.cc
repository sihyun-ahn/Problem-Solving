#include <iostream>
#include <queue>
using namespace std;

void bfs(int *count, int n, int k) {
  queue<int> q;
  int front, cnt = 0;
  q.push(n);
  count[n] = 0;
  while (!q.empty()) {
    front = q.front();
    if (front == k) {
      cout << count[front];
      break;
    }
    q.pop();
    if (front + 1 >= 0 && front + 1 <= 100000 && count[front + 1] == -1) {
      q.push(front + 1);
      count[front + 1] = count[front] + 1;
    }
    if (front - 1 >= 0 && front - 1 <= 100000 && count[front - 1] == -1) {
      q.push(front - 1);
      count[front - 1] = count[front] + 1;
    }
    if (front * 2 >= 0 && front * 2 <= 100000 && count[front * 2] == -1) {
      q.push(front * 2);
      count[front * 2] = count[front] + 1;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, k;
  cin >> n >> k;
  int *count = new int[100001]();
  for (int i=0; i<=100000; i++) {
    count[i] = -1;
  }
  bfs(count, n, k);
  delete[] count;
  return 0;
}