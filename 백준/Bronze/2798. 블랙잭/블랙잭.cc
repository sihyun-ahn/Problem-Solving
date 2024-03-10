#include <iostream>
using namespace std;



int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, m, sum, max = 0;
  cin >> n >> m;
  int *card = new int[n];
  for (int i=0; i<n; i++) {
    cin >> card[i];
  }
  for (int i=0; i<n; i++) {
    for (int j=i+1; j<n; j++) {
      for (int k=j+1; k<n; k++) {
        sum = card[i] + card[j] + card[k];
        if (sum <= m && sum > max) {
          max = sum;
        }
      }
    }
  }
  cout << max;

  return 0;
}