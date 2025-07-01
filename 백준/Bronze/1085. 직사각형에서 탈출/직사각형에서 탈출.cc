#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int x, y, w, h;
    vector<int> v;
    cin >> x >> y >> w >> h;
    cout << min({x, y, w - x, h - y});
    return 0;
}
