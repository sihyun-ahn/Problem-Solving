#include <iostream>
#include <stack>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, e, prevE = 0;
  stack<int> s;
  stack<int> nge;
  stack<int> candidate;
  cin >> n;
  for (int i=0; i<n; i++) {
    cin >> e;
    s.push(e);
  }
  while(!s.empty()) {
    while (!candidate.empty()) {
      if (s.top() < candidate.top()) {
        nge.push(candidate.top());
        break;
      } else {
        candidate.pop();
      }
    }
    if (candidate.empty()) {
      nge.push(-1);
    }
    prevE = s.top();
    candidate.push(prevE);
    s.pop();
  }
  while(!nge.empty()) {
    cout << nge.top() << ' ';
    nge.pop();
  }
  return 0;
}