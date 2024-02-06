#include <iostream>
#include <array>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(array<int, 2> a1, array<int, 2> a2) {
  if (a1[0] < a2[0])
    return true;
  else if (a1[0] > a2[0])
    return false;
  else
    return (a1[1] < a2[1]);
}


int main() {
  int len, i, x, y;
  vector<array<int, 2>> vec;
  cin >> len;

  for (i = 0; i < len; i ++) {
    cin >> x >> y;
    vec.push_back({x, y});
  }

  sort(vec.begin(), vec.end(), compare);

  for (const auto& element : vec) {
    cout << element[0] << ' ' << element[1] << '\n';
  }
  return 0;
}