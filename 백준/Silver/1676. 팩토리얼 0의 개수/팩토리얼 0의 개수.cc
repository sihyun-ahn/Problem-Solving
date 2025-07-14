#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  int n, two=0, five=0, res = 0;
  cin >> n;

  for (int i=1; i<=n; i++) {
    int j = i;
    int k = i;

    while (j >= 2 && j % 2 == 0) {
      two ++;
      j = j/2;
    }

    while (k >= 5 && k % 5 == 0) {
      five ++;
      k = k/5;
    }      
  }

  res = min(two, five);

  cout << res;

  return 0;
}