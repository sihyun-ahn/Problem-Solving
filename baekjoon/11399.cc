#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, cnt = 0;
  cin >> n;
  int *time = new int[n]();
  for (int i=0; i<n; i++) {
    cin >> time[i];
  }
  sort(time, time + n);
  for (int i=0; i<n; i++) {
    cnt += time[i] * (n - i);
  }
  cout << cnt;
  delete[] time;

  return 0;
}