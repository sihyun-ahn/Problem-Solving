#include <iostream>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, a, b;
  cin >> n;
  int *numbers = new int[n]();

  for (int i=0; i<n; i++) {
    cin >> a >> b;
    numbers[i] = a + b;
  }

  for (int i=0; i<n; i++) {
    cout << numbers[i] << '\n';
  }

  delete[] numbers;

  return 0;
}