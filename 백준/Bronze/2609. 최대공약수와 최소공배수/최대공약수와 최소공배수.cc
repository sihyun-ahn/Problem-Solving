#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int a, b, temp, mul = 1;
  cin >> a >> b;
  for (int i=min({a, b}); i>0; i--) {
    if (a % i == 0 && b % i == 0) {
      cout << i << '\n';
      break;
    }
  }
  while (true) {
    temp = mul * min({a, b});
    if (temp % max({a, b}) == 0) {
      cout << temp;
      break;
    }
    mul ++;
  }
  return 0;
}