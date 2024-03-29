#include <iostream>
#include <vector>
using namespace std;

void basicStar(vector<vector<char>>& stars, int level) {
  // 1st level
  stars.at(level).push_back(' ');
  stars.at(level).push_back(' ');
  stars.at(level).push_back('*');
  stars.at(level).push_back(' ');
  stars.at(level).push_back(' ');
  stars.at(level).push_back(' ');
  // 2nd level
  stars.at(level + 1).push_back(' ');
  stars.at(level + 1).push_back('*');
  stars.at(level + 1).push_back(' ');
  stars.at(level + 1).push_back('*');
  stars.at(level + 1).push_back(' ');
  stars.at(level + 1).push_back(' ');
  // 3rd level
  stars.at(level + 2).push_back('*');
  stars.at(level + 2).push_back('*');
  stars.at(level + 2).push_back('*');
  stars.at(level + 2).push_back('*');
  stars.at(level + 2).push_back('*');
  stars.at(level + 2).push_back(' ');
}

void rec(vector<vector<char>>& stars, int depth, int level) {
  if (depth == 1) {
    basicStar(stars, level);
    return;
  }
  for (int i=0; i<depth/2 * 3; i++) {
    for (int j=0; j<depth/2 * 3; j++) {
      stars.at(level + i).push_back(' ');
    }
  }
  rec(stars, depth / 2, level);
  rec(stars, depth / 2, level + depth / 2 * 3);
  rec(stars, depth / 2, level + depth / 2 * 3);
  for (int i=0; i<depth/2 * 3; i++) {
    for (int j=0; j<depth/2 * 3; j++) {
      stars.at(level + i).push_back(' ');
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  vector<vector<char>>::iterator outer;
  vector<char>::iterator inner;
  cin >> n;
  vector<vector<char>> stars(n);
  rec(stars, n/3, 0);
  for (outer = stars.begin(); outer != stars.end(); outer ++) {
    for (inner = (*outer).begin(); inner != (*outer).end(); inner ++) {
      cout << (*inner);
    }
    cout << '\n';
  }
  return 0;
}