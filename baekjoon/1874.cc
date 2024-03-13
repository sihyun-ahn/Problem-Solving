#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, prevMax = 0, curMax = 0;
  stack<int> s;
  vector<char> v;
  bool increasing = true;
  cin >> n;
  int *array = new int[n]();
  for (int i=0; i<n; i++) {
    cin >> array[i];
  }
  int i = 1;
  int j = 0;
  increasing = true;
  while (j < n) {
    if (array[j] < i) {
      if (!s.empty() && array[j] == s.top()) {
        v.push_back('-');
        s.pop();
        j++;
        continue;
      } else {
        cout << "NO";
        delete[] array;
        return 0;
      } 
    }
    while (array[j] > i) {
      s.push(i++);
      v.push_back('+');
    }
    s.push(i++);
    v.push_back('+');        
    s.pop();
    v.push_back('-');
    j++;
  }
  for (vector<char>::iterator iter = v.begin(); iter != v.end(); iter ++) {
    cout << *iter << '\n';
  }
  delete[] array;
  return 0;
}