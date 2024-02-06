#include <iostream>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, a, b;
  cin >> n;
  int* ans = new int[n]();

  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    ans[i] = a+b;
  }

  for (int i = 0; i < n; i++) {
    cout << ans[i] << '\n';
  }  

  return 0;
}