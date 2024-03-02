#include <iostream>
#include <cmath>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, mul, num, cnt = 0;
  cin >> n;
  bool visited[1001] = { false };
  visited[1] = true;
  for (int i=2; i<=sqrt(1000); i++) {
    if (!visited[i]) {
      mul = 2;
      while (mul * i <= 1000) {
        visited[mul * i] = true;
        mul ++;
      }
    }
  }
  for (int i=0; i<n; i++) {
    cin >> num;
    if (!visited[num]) {
      cnt ++;
    }
  }
  cout << cnt;
  return 0;
}