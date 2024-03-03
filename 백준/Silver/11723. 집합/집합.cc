#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t, operand;
  string cmd;
  bool set[20] = { false };
  cin >> t;
  for (int i=0; i<t; i++) {
    cin >> cmd;
    if (cmd == "add") {
      cin >> operand;
      set[operand] = true;
    } else if (cmd == "remove") {
      cin >> operand;
      set[operand] = false;
    } else if (cmd == "check") {
      cin >> operand;
      if (set[operand]) {
        cout << "1\n";
      } else {
        cout << "0\n";
      }
    } else if (cmd == "toggle") {
      cin >> operand;
      set[operand] = !set[operand];
    } else if (cmd == "all") {
      fill(set + 1, set + 21, 1);
    } else if (cmd == "empty") {
      fill(set + 1, set + 21, 0);
    }
  }
  
  return 0;
}