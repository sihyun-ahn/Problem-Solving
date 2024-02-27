#include <iostream>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);
  int i;
  string s;
  cin >> s >> i;
  cout << s[i - 1];
  return 0;
}