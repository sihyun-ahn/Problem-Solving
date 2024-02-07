#include <iostream>
#include <algorithm>
using namespace std;

struct Obj {
  int w;
  int v;
};

bool compareObjects(const Obj& obj1, const Obj& obj2) {
    return obj1.w < obj2.w;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, k;
  cin >> n >> k;
  Obj* objects = new Obj[n];
  int** dp = new int*[n]();
  for (int i=0; i<n; i++) {
    cin >> objects[i].w >> objects[i].v;
  }
  sort(objects, objects + n, compareObjects);

  for (int i=0; i<n; i++) {
    dp[i] = new int[k+1]();
    for (int j=0; j<=k; j++) {
      // cout << objects[i].w << " " << objects[i].v << '\n';
      if (i == 0) {
        dp[i][j] = (objects[i].w > j) ? 0 : objects[i].v;
      } else {
        dp[i][j] = (objects[i].w > j) ? dp[i - 1][j] : max({objects[i].v + dp[i - 1][j - objects[i].w], dp[i][j - 1], dp[i-1][j]});
      }
    }
  }

  cout << dp[n-1][k];

  delete[] objects;
  delete[] dp;

  return 0;
}