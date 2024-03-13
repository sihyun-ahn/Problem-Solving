#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  string s;
  bool add = true;
  int numStart, operand, result = 0, i = 0;
  cin >> s;
  while (i < s.size()) {
    if (isdigit(s.at(i))) {
      numStart = i;
      while (i < s.size() && isdigit(s.at(i))) {
        i ++;
      }
      operand = stoi(s.substr(numStart, i - numStart));
      if (add) {
        result += operand;
      } else {
        result -= operand;
      }
    } else {
      if (add) {
        if (s.at(i) == '-') {
          add = false;
        }
      }
      i ++;
    }
  }
  cout << result;
  return 0;
}