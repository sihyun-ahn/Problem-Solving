#include <iostream>
using namespace std;

int main() {
  int h, m, t;
  cin >> h >> m >> t;
  int mout = m + t;
  int hout = h;
  while (mout >= 60) {
    mout -= 60;
    hout += 1;
  }
  while (hout >= 24) {
    hout -= 24;
  }
  cout << hout << " " << mout;
}