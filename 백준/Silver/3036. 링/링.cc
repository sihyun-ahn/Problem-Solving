#include <iostream>
using namespace std;

int gcd(int a, int b) {
  return b ? gcd(b, a%b) : a;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, denom, num, divider;
  cin >> n >> denom;
  for (int i=0; i<n-1; i++) {
    cin >> num;
    divider = gcd(num, denom);
    cout << denom / divider << '/' << num / divider << '\n';
  }
  return 0;
}