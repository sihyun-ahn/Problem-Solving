#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, t;

  cin >> t;
  int* ans = new int[t];
  for (int i=0; i<t; i++) {
    cin >> n;
    int* file = new int[n];
    int** cost = new int*[n];
    int** sum = new int*[n];
    for (int i=0; i<n; i++) {
      cin >> file[i];
      cost[i] = new int[n]();
      sum[i] = new int[n]();
    }

    for (int i=0; i<n; i++) {
      int fileSum = 0;
      for (int j=i; j<n; j++) {
        fileSum += file[j];
        sum[i][j] = fileSum;
      }
    }

    for (int i=n-1; i>=0; i--) {
      for (int j=i+1; j<n; j++) {
        int* temp = new int[j - i]();
        for (int k=i; k<j; k++) {
          temp[k-i] = cost[i][k] + cost[k+1][j];
        }
        cost[i][j] = *min_element(temp, temp+j-i) + sum[i][j];
        delete[] temp;
      }
    }
    ans[i] = cost[0][n-1];
    delete[] file;
    delete[] sum;
    delete[] cost;
  }

  for (int i=0; i<t; i++) {
    cout << ans[i] << '\n';
  }

  delete[] ans;
  return 0;
}