#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, operand;
  string cmd;
  stack<int> s;
  queue<int> q;
  cin >> n;
  for (int i=0; i<n; i++) {
    cin >> cmd;
    if (cmd == "push") {
      cin >> operand;
      s.push(operand);
    } else if (cmd == "pop") {
      if (s.empty()) {
        // cout << -1 << '\n';
        q.push(-1);
      } else {
        // cout << s.top();
        q.push(s.top());
        s.pop();        
      }
    } else if (cmd == "size") {
      // cout << s.size() << '\n';
      q.push(s.size());
    } else if (cmd == "empty") {
      if (s.empty()) {
        // cout << 1 << '\n';
        q.push(1);
      } else {
        // cout << 0 << '\n';
        q.push(0);
      }
    } else if (cmd == "top") {
      if (s.empty()) {
        // cout << -1 << '\n';
        q.push(-1);
      } else {
        // cout << s.top() << '\n';
        q.push(s.top());
      }
    }
  }

  while (!q.empty()) {
    cout << q.front() << '\n';
    q.pop();
  }
  return 0;
}