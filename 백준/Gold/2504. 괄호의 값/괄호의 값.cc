#include <iostream>
#include <stack>
using namespace std;

int calculateScore(string s, int start, int end) {
  stack<char> p;
  int innerScore, newStart = start, score = 0;
  if (start > end) {
    return 1;
  }
  for (int i = start; i <= end; i ++) {
    if (s[i] == '(' || s[i] == '[') {
      p.push(s[i]);
    } else if (s[i] == ')' && !p.empty() && p.top() == '(') {
      p.pop();
      if (p.empty()) {
        innerScore = calculateScore(s, newStart + 1, i - 1);
        if (innerScore == 0) return 0;
        score += 2 * innerScore;
        newStart = i + 1;
      }
    } else if (s[i] == ']' && !p.empty() && p.top() == '[') {
      p.pop();
      if (p.empty()) {
        innerScore = calculateScore(s, newStart + 1, i - 1);
        if (innerScore == 0) return 0;
        score += 3 * innerScore; 
        newStart = i + 1; 
      }  
    } else {
      score = 0;
      break;
    }
  }
  if (!p.empty()) score = 0;
  return score;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    cin >> s;
    cout << calculateScore(s, 0, s.length() - 1);
    return 0;
}