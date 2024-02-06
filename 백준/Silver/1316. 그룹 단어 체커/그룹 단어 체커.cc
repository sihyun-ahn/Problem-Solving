#include <iostream>
using namespace std;

int main() {
  int len, i, j, k;
  bool isGroup = true;
  bool isChanged = false;
  int out = 0;
  string word;

  cin >> len;
  for (i = 0; i < len; i ++) {
    cin >> word;
    for (j = 0; j < word.size() - 1; j ++) {
      char c = word[j];
      for (k = j + 1; k < word.size(); k ++) {
        if (isChanged && word[k] == c) {
          isGroup = false;
        }
        if (!isChanged && word[k] != c) {
          isChanged = true;
        }
      }
      isChanged = false;
    }
    if (isGroup) out ++;
    isGroup = true;
  }
  
  cout << out;
  return 0;
}