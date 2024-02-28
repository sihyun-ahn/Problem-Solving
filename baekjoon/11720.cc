#include <iostream>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, sum = 0;
  char c;
  
  cin >> n;

  for (int i=0; i<n; i++) {
    cin >> c;
    sum += (c - '0');
  }
  cout << sum;
  return 0;
}