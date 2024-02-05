#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(string s1, string s2) {
  if (s1.size() < s2.size()) 
    return true;
  else if (s1.size() > s2.size())
    return false;
  else
    return (s1 < s2);
}

int main() {
  int len, i;
  string input;
  cin >> len;
  vector<string> vec;
  for (i = 0; i < len; i ++) {
    cin >> input;
    vec.push_back(input);
  }

  sort(vec.begin(), vec.end(), compare);
  auto last = unique(vec.begin(), vec.end());
  vec.erase(last, vec.end());
  
  for (const auto& element : vec) {
    cout << element << endl;
  }

  return 0;
}