#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int num[9] = {0};

    for (int i = 0; i < 9; i++) {
        cin >> num[i];
    }
    
    int *max = max_element(num, num + 9);
    cout << *max << '\n' << max - num + 1;

    return 0;
}
