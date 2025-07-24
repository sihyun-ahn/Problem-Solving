#include <iostream>
using namespace std;

void connect(int n, int **friends, int mediator) {
  for (int i=0; i<n - 1; i++) {
    if (friends[mediator][i] != 1) continue;
    for (int j=i + 1; j<n; j++) {
      if (friends[mediator][j] != 1) continue;
      if (friends[i][j] == 1) continue;
      friends[i][j] = 2;
      friends[j][i] = 2;
    }
  }
}

int main() {
  cin.tie(NULL);
  cout.tie(NULL);

  int n, famous = 0;
  cin >> n;

  // 1: 1-friend, 2: 2-friend
  int **friends = new int*[n];
  int *friends_n = new int[n]();

  for (int i=0; i<n; i++) {
    string input;
    cin >> input;
    friends[i] = new int[n]();
    for (int j=0; j<n; j++) {
      char is_friend = input.c_str()[j];
      if (is_friend == 'Y') {
        friends[i][j] = 1;
        friends_n[i] ++;
        // friends[j][i] = 1;
      }
    }
  }

  for (int i=0; i<n; i++) {
    if (friends_n[i] > 1) {
      connect(n, friends, i);
    }
  }

  for (int i=0; i<n; i++) {
    int cnt = 0;
    for (int j=0; j<n; j++) {
      if (friends[i][j] > 0) cnt ++;
    }
    if (cnt > famous) {
      famous = cnt;
    }
  }
  
  cout << famous;

  return 0;
}