#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    double n, res, score, sum = 0.0, max = 0.0;
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> score;
        if (score > max) {
            max = score;
        }
        sum += score;
    }
    res = (sum * 100.0 / (max * n));
    cout << res;
    return 0;
}