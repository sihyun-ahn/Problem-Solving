#include <iostream>
#include <set>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  set<int> s;
  for (int i=0; i<10; i++) {
    cin >> n;
    s.insert(n % 42);
  }
  cout << s.size();
  return 0;
}