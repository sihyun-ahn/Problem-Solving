#include <iostream>
#include <queue>
#include <stack>
#include <cctype>
#include <string>
using namespace std;

void convert(string input) {
  stack<char> ops;
  queue<char> res;
  char top;
  for (int i=0; i<input.size(); i++) {
    if (isalpha(input[i])) {
      // operand
      res.push(input[i]);
    } else if (input[i] == '(') {
      // parenthesis opend
      ops.push(input[i]);
    } else if (input[i] == ')') {
      // parenthesis closed
      while(!ops.empty() && ops.top() != '(') {
        res.push(ops.top());
        ops.pop();
      }
      ops.pop();
    } else if (input[i] == '+' || input[i] == '-') {
      while(!ops.empty() && ops.top() != '(' ) {
        res.push(ops.top());
        ops.pop();
      }
      ops.push(input[i]);
    } else if (input[i] == '*' || input[i] == '/') {
      while(!ops.empty() && ops.top() != '(' && ops.top() != '+' && ops.top() != '-') {
        res.push(ops.top());
        ops.pop();
      } 
      ops.push(input[i]);     
    }
  }
  while (!ops.empty()) {
    res.push(ops.top());
    ops.pop();
  }
  while (!res.empty()) {
    cout << res.front();
    res.pop();
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  string equation;
  cin >> equation;
  convert(equation);
  return 0;
}
