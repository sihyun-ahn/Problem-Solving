#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

void calculate(vector<int> v, string cmd) {
  bool reversed = false;
  vector<int>::iterator start = v.begin();
  vector<int>::iterator end = v.end() - 1;
  for (int i = 0; i<cmd.size(); i++) {
    if (cmd[i] == 'R') {
      reversed = !reversed;
    } else if (cmd[i] == 'D') {
      if (v.empty() || start > end) {
        cout << "error\n";
        return;
      }
      if (!reversed) {
        // v.erase(v.begin());
        start ++;
      } else {
        // v.erase(v.end() - 1);
        end --;
      }
    }
  }
  if (v.empty() || start > end) {
    cout << "[]\n";
    return;
  }
  if (!reversed) {
    cout << '[';
    for (vector<int>::iterator iter = start; iter != end; iter ++) {
      cout << *iter << ',';
    }
    cout << *end << "]\n";
  } else {
    cout << '[';
    for (vector<int>::iterator iter = end; iter != start; iter --) {
      cout << *iter << ',';
    }
    cout << *(start) << "]\n";
  }
  return;
}

int main() {
  // ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t, n;
  string cmd, arrayString, buffer;
  cin >> t;
  for (int i=0; i<t; i++) {
    cin >> cmd >> n >> arrayString;
    vector<int> v;
    istringstream ss(arrayString.substr(1, arrayString.size() - 2));
    while (getline(ss, buffer, ',')) {
      v.push_back(stoi(buffer));
    }
    calculate(v, cmd);
  }
  return 0;
}