#include <iostream>
#include <map>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, card, m;
  map<int, int> map;
  cin >> n;
  for (int i=0; i<n; i++) {
    cin >> card;
    map[card] ++;
  }
  cin >> m;
  for (int i=0; i<m; i++) {
    cin >> card;
    cout << map[card] << ' ';
  }
  
  return 0;
}