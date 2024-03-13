#include <iostream>
#include <algorithm>
#include <cmath>
#include <limits>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, start, end, res1, res2, sum = numeric_limits<int>::max();
  cin >> n;
  int *array = new int[n]();
  for (int i=0; i<n; i++) {
    cin >> array[i];
  }
  sort(array, array + n);
  start = 0;
  end = n - 1;
  while (start < end) {
    if (abs(array[start] + array[end]) < abs(sum)) {
      sum = array[start] + array[end];
      res1 = start;
      res2 = end;
    }
    if (array[start] + array[end] < 0) {
      start ++;
    } else {
      end --;
    }
  }
  cout << array[res1] << ' ' << array[res2];
  delete[] array;
  return 0;
}