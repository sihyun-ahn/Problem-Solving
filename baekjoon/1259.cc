#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  string s;
  bool isPelindrom;
  vector<bool> res;

  while (true) {
    cin >> s;
    if (s == "0") {
      break;
    }
    isPelindrom = true;
    for (int i=0; i<s.size()/2; i++) {
      if (s[i] != s[s.size() - 1 - i]) {
        isPelindrom = false;
        break;
      }
    }
    res.push_back(isPelindrom);
  }

  for (vector<bool>::iterator iter = res.begin(); iter != res.end(); iter ++) {
    if (*iter == 0) {
      cout << "no\n";
    } else {
      cout << "yes\n";
    }
  }  

  return 0;
}