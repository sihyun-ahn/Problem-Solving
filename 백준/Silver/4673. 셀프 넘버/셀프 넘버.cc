#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int main() {
 int i;
 set <int> s;
 set <int>::iterator iter;
 int last = 1;
 for (i = 1; i <= 10000 ; i ++) {
   s.insert(i + i % 10 + ((i / 10) % 10) + ((i / 100) % 10) + ((i / 1000) % 10) + ((i / 10000) % 10));
 }
  for (iter = s.begin(); iter != s.end(); iter ++) {
    for (i = last; i < min({*iter, 10000}); i ++)
      cout << i << endl;
    last = *iter + 1;
    if (last > 10000) break;
  }
}