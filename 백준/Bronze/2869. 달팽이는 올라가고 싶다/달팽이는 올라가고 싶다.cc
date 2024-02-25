#include <iostream>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(0);
    long a, b, v;
    cin >> a >> b >> v;
    if (v <= a) {
        cout << 1;
        return 0;
    }

    cout << static_cast<long>(ceil((long double)(v-a)/(a-b))) + 1;
    return 0;
}
