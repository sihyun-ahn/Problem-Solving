#include <iostream>
#include <algorithm>
using namespace std;

void dfsNormal(char **map, bool **visitedNormal, int x, int y, int n) {
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {1, -1, 0, 0};
    for (int i=0; i<4; i++) {
        int newX = x + dx[i];
        int newY = y + dy[i];
        if (newX >=0 && newX < n && newY >= 0 && newY < n && !visitedNormal[newX][newY] && map[newX][newY] == map[x][y]) {
            visitedNormal[newX][newY] = true;
            dfsNormal(map, visitedNormal, newX, newY, n);
        }
    }
}

void dfsBlind(char **map, bool **visitedBlind, int x, int y, int n) {
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {1, -1, 0, 0};
    for (int i=0; i<4; i++) {
        int newX = x + dx[i];
        int newY = y + dy[i];
        if (newX >=0 && newX < n && newY >= 0 && newY < n && !visitedBlind[newX][newY]) {
            if (map[newX][newY] == map[x][y] || (map[newX][newY] == 'G' && map[x][y] == 'R') || (map[newX][newY] == 'R' && map[x][y] == 'G')) {
                visitedBlind[newX][newY] = true;
                dfsBlind(map, visitedBlind, newX, newY, n);  
            }
        }
    }
}

int main() {
    int n, normal = 0, blind = 0;
    cin >> n;
    char **map = new char*[n];
    bool **visitedNormal = new bool*[n];
    bool **visitedBlind = new bool*[n];

    for (int i=0; i<n; i++) {
        map[i] = new char[n];
        visitedNormal[i] = new bool[n]();
        visitedBlind[i] = new bool[n]();
        for (int j=0; j<n; j++) {
            cin >> map[i][j];
        }
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (!visitedNormal[i][j]) {
                dfsNormal(map, visitedNormal, i, j, n);
                normal ++;
            }
            if (!visitedBlind[i][j]) {
                dfsBlind(map, visitedBlind, i, j, n);
                blind ++;
            }
        }
    }

    cout << normal << ' ' << blind;
    delete[] map;
    delete[] visitedBlind;
    delete[] visitedNormal;

    return 0;
}