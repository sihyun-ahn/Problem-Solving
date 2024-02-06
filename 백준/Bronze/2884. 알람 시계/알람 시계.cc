#include <iostream>
using namespace std;

int main() {
  int h, m;
  cin >> h >> m;
  int mout = m - 45;
  int hout = h;
  if (mout < 0) {
    mout += 60;
    hout -= 1;
  }
  if (hout < 0) {
    hout += 24;
  }
  cout << hout << " " << mout;
}