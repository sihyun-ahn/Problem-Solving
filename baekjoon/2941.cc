#include <iostream>
using namespace std;

int main() {
  string input;
  int i = 0;
  int len = 0;
  
  cin >> input;
  for (i; i < input.size(); i++) {
    if (input[i] == 'c' && (input[i + 1] == '=' || input[i + 1] == '-')) {
      i ++;
      len ++;
      continue;
    }
    if (input[i] == 'd') {
      if (input[i + 1] == 'z' && input[i + 2] == '=') {
        i += 2;
        len ++;
        continue;
      } else if (input[i + 1] == '-') {
        i ++;
        len ++;
        continue;
      }
    }
    if (input[i] == 'l' && input[i + 1] == 'j') {
      i ++;
      len ++;
      continue;
    }
    if (input[i] == 'n' && input[i + 1] == 'j') {
      i ++;
      len ++;
      continue;
    }
    if (input[i] == 's' && input[i + 1] == '=') {
      i ++;
      len ++;
      continue;
    }
    if (input[i] == 'z' && input[i + 1] == '=') {
      i ++;
      len ++;
      continue;
    }
    len ++;
  }

  cout << len;
  return 0;
}