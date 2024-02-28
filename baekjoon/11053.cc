#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    int *list = new int[n]();
    int *dp = new int[n]();
    for (int i=0; i<n; i++) {
        cin >> list[i];
    }
    for (int i=0; i<n; i++) {
        int max = 1;
        int length = 1;
        for (int j=0; j<i; j++) {
            if (list[j] < list[i]) {
                length = dp[j] + 1;
                if (length >= max) {
                    max = length;
                }
            }
        }
        dp[i] = max;
    }
    cout << *max_element(dp, dp + n);
    delete[] list;
    delete[] dp;
    return 0;
}
