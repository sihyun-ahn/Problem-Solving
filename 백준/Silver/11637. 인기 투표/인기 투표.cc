#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t, n, vote, sum, max, winner;
    bool noWinner = false;
    cin >> t;
    for (int i=0; i<t; i++) {
      cin >> n;
      sum = 0;
      max = 0;
      winner = 1;
      for (int j=1; j<=n; j++) {
        cin >> vote;
        sum += vote;
        if (vote > max) {
          noWinner = false;
          max = vote;
          winner = j;
        } else if (vote == max) {
          noWinner = true;
        }
      }
      if (noWinner) {
        cout << "no winner\n";
      } else if (max > sum / 2) {
        cout << "majority winner " << winner << '\n';
      } else {
        cout << "minority winner " << winner << '\n';
      }
    }
    return 0;
}