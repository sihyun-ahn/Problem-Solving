#include <iostream>
#include <queue>
#include <array>

using namespace std;

void bfs(char **map, int n, int m) {
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {1, -1, 0, 0};
    int **count = new int*[n];
    for (int i=0; i<n; i++) {
        count[i] = new int[m]();
    }
    count[0][0] = 1;
    queue<array<int, 2>> q;
    q.push({0, 0});
    while (!q.empty()) {
        array<int, 2> front = q.front();
        q.pop();
        for (int i=0; i<4; i++) {
            int newX = front[0] + dx[i];
            int newY = front[1] + dy[i];
            if (newX >= 0 && newX < n && newY >=0 && newY < m && map[newX][newY] == '1') {
                if (count[newX][newY] == 0) {
                    count[newX][newY] = count[front[0]][front[1]] + 1;
                    if (newX == n-1 && newY == m-1) {
                        cout << count[newX][newY];
                        delete[] count;
                        return;
                    }
                    q.push({newX, newY});
                }
            }
        }
    }
    delete[] count;
    return;
}

int main() {
    int n, m;
    cin >> n >> m;
    char **map = new char*[n];
    for (int i=0; i<n; i++) {
        string input;
        cin >> input;
        map[i] = new char[m]();
        for (int j=0; j<m; j++) {
            map[i][j] = input.c_str()[j];
        }
    }
    bfs(map, n, m);
    delete[] map;
    return 0;
}
