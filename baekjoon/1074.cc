#include <iostream>
#include <cmath>
using namespace std;

int cnt = 0;
void recursion(int n, int r, int c) {
  if (n <= 0) {
    return;
  }
  if (r < pow(2, n-1) && c < pow(2, n-1)) {
    recursion(n - 1, r, c);
  } else if (r < pow(2, n-1)) {
    cnt += pow(2, n - 1) * pow(2, n - 1);
    recursion(n - 1, r, c - pow(2, n-1));
  } else if (c < pow(2, n-1)) {
    cnt += 2 * pow(2, n - 1) * pow(2, n - 1);
    recursion(n - 1, r - pow(2, n-1), c);
  } else {
    cnt += 3 * pow(2, n - 1) * pow(2, n - 1);
    recursion(n - 1, r - pow(2, n-1), c - pow(2, n-1));
  }
  return;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, r, c;
  cin >> n >> r >> c;
  recursion(n, r, c);
  cout << cnt;
  return 0;
}