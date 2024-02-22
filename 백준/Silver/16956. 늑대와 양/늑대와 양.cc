#include <iostream>
#include <array>
#include <vector>
using namespace std;

int main() {
    int r, c;
    cin >> r >> c;
    char** map = new char*[r];
    vector<array<int, 2>> sheeps;
    for (int i = 0; i < r; i++) {
        map[i] = new char[c];
        for (int j = 0; j < c; j++) {
            char temp;
            cin >> temp;
            if (temp == '.') {
                map[i][j] = 'D';
            } else if (temp == 'S') {
                sheeps.push_back({i, j});
                map[i][j] = temp;
            } else {
                map[i][j] = temp;
            }
        }
    }

    for (const auto& element : sheeps) {
        if ((element[0] < r - 1 && map[element[0] + 1][element[1]] == 'W') || (element[1] < c - 1 && map[element[0]][element[1] + 1] == 'W') || (element[0] > 0 && map[element[0] - 1][element[1]] == 'W') || (element[1] > 0 && map[element[0]][element[1] - 1] == 'W')) {
            cout << 0;
            return 0; 
        }
    }

    cout << 1 << "\n";
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << map[i][j];
        }
        cout << "\n";
    }
    return 0;
}
