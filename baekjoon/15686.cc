#include <iostream>
#include <vector>
#include <array>
using namespace std;

void dfs(char **map, bool **visitedNormal, int x, int y, int n) {
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {1, -1, 0, 0};

}


int main() {
    int n, m;
    cin >> n >> m;
    char **map = new char*[n];
    vector<array<int, 2>> house;
    vector<array<int, 2>> chicken;

    for (int i=0; i<n; i++) {
        map[i] = new char[n];
        for (int j=0; j<n; j++) {
            cin >> map[i][j];
            if (map[i][j] == 1) {
                house.push_back({i, j});
            } else if (map[i][j] == 2) {
                chicken.push_back({i, j});
            }
        }
    }


    delete[] map;

    return 0;
}
