#include <iostream>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, remain, cnt = 0;
  cin >> n;
  remain = n;
  while (remain >= 5) {
    remain -= 5;
    cnt ++;
  }
  while (remain % 3 != 0 && cnt > 0) {
    remain += 5;
    cnt --;
  }
  if (remain % 3 != 0) {
    cout << -1;
  } else {
    cnt += remain / 3;
    cout << cnt;
  }

  return 0;
}