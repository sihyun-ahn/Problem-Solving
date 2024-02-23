#include <iostream>
#include <vector>
#include <array>
using namespace std;
int cnt = 0;

void rec(int cur, int rest, int target, int n, vector<array<int, 2>>& v) {
    cnt += 1;
    if (n == 1) {
        v.push_back({cur, target});
        return;
    }
    rec(cur, target, rest, n-1, v);
    v.push_back({cur, target});
    rec(rest, cur, target, n-1, v);
}

int main() {
    int n;
    cin >> n;
    vector<array<int, 2>> v;
    vector<array<int, 2>>::iterator iter;
    rec(1, 2, 3, n, v);
    
    cout << cnt << '\n';
    for (iter = v.begin(); iter != v.end(); iter++) {
        cout << (*iter)[0] << ' ' << (*iter)[1] << '\n';
    }
    return 0;
}
