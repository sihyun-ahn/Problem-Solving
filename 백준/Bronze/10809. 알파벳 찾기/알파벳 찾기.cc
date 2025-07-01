#include <iostream>
#include <string>
using namespace std;

int main() {
  string s;
  cin >> s;
  int a = int('a');
  int z = int('z');
  for (int i = a; i <= z; i++) {
    int res = s.find(char(i));
    if (res == string::npos) res = -1;
    cout << res << ' ';
  }
  return 0;
}