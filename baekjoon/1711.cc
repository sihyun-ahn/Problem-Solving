#include <iostream>
#include <vector>
#include <array>
using namespace std;

void countRightTriangle(vector<array<long, 2>> vertex) {
  vector<array<long, 2>>::iterator iter1, iter2, iter3;
  long long a, b, c;
  int cnt = 0;
  for (iter1 = vertex.begin(); iter1 != vertex.end() - 2; iter1 ++) {
    for (iter2 = iter1 + 1; iter2 != vertex.end() - 1; iter2 ++) {
      for (iter3 = iter2 + 1; iter3 != vertex.end(); iter3 ++) {
        a = ((*iter1)[0] - (*iter2)[0]) * ((*iter1)[0] - (*iter2)[0]) + ((*iter1)[1] - (*iter2)[1]) * ((*iter1)[1] - (*iter2)[1]);
        b = ((*iter1)[0] - (*iter3)[0]) * ((*iter1)[0] - (*iter3)[0]) + ((*iter1)[1] - (*iter3)[1]) * ((*iter1)[1] - (*iter3)[1]);
        c = ((*iter2)[0] - (*iter3)[0]) * ((*iter2)[0] - (*iter3)[0]) + ((*iter2)[1] - (*iter3)[1]) * ((*iter2)[1] - (*iter3)[1]);
        if (a == b + c || b == a + c || c == a + b) {
          cnt ++;
        }
      }
    }
  }
  cout << cnt;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, res = 0;
  long x, y;
  vector<array<long, 2>> vertex;
  cin >> n;
  for (int i=0; i<n; i++) {
    cin >> x >> y;
    vertex.push_back({x, y});
  }
  countRightTriangle(vertex);
  return 0;
}