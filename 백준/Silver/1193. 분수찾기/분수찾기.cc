#include <iostream>
using namespace std;

int sumUp(int n) {
  return n * (n + 1) / 2;
}

void evenIdx(int input, int i) {
  int denom = input - sumUp(i);
  int num = (i + 2) - denom;

  cout << num << '/' << denom;
}

void oddIdx(int input, int i) {
  int num = input - sumUp(i);
  int denom = (i + 2) - num;

  cout << num << '/' << denom;
}

int main() {
  int input, num, denom, i = 0;
  cin >> input;

  while (sumUp(i) < input) {
    i ++;
    if (sumUp(i) >= input) {
      i --;
      break;
    }
  }

  if (i % 2 == 0)
    evenIdx(input, i);
  else
    oddIdx(input, i);

  return 0;
}