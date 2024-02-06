#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
  int i;
  vector<int> vec;
  cin >> i;

  do {
    vec.push_back(i % 10);
    i = i / 10;
  } while (i > 0);

  sort(vec.begin(), vec.end(), [](int a, int b) { return a > b; });

  for (int num : vec) {
    cout << num;
  }
  return 0;
}