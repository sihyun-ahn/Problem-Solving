#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  int *numbers = new int[n]();

  for (int i=0; i<n; i++) {
    cin >> numbers[i];
  }


  cout << *min_element(numbers, numbers + n) << ' ' << *max_element(numbers, numbers + n);

  return 0;
}