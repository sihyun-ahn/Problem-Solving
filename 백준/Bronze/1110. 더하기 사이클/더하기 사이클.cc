#include <iostream>
using namespace std;

int main() {
  int n_ori, n, new_n, cycle = 0;
  cin >> n_ori;
  n = n_ori;
  do {
    new_n = (n%10 + n/10) % 10 + n%10 * 10;
    cycle ++;
    n = new_n;
  } while (n != n_ori);
  
  cout << cycle;

  return 0;
}