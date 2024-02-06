#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  int list[3] = {a, b, c};
  sort(list, list + 3);
  if (list[0] == list[2])
    cout << 10000 + list[0] * 1000;
  else if (list[0] == list[1])
    cout << 1000 + list[1] * 100;
  else if (list[1] == list[2])
    cout << 1000 + list[1] * 100;
  else
    cout << 100 * list[2];
  return 0;
}