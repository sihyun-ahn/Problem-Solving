#include <iostream>
#include <queue>
#include <array>
#include <algorithm>
#include <vector>

using namespace std;

void bfs(int **map, int **count, bool **visited, int n, int m, queue<array<int, 2>> q) {
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {1, -1, 0, 0};
    while (!q.empty()) {
        array<int, 2> front = q.front();
        q.pop();
        for (int i=0; i<4; i++) {
            int newX = front[0] + dx[i];
            int newY = front[1] + dy[i];
            if (newX >= 0 && newX < n && newY >=0 && newY < m && map[newX][newY] == 0 && !visited[newX][newY]) {   
                count[newX][newY] = (count[newX][newY] == -1) ? count[front[0]][front[1]] + 1: min({count[newX][newY], count[front[0]][front[1]] + 1});
                q.push({newX, newY});
                visited[newX][newY] = true;
            }
        }
    }
    return;
}

int main() {
    int n, m, max = -1;
    cin >> m >> n;
    int **map = new int*[n];
    int **count = new int*[n];
    bool **visited = new bool*[n];

    queue<array<int, 2>> q;
    for (int i=0; i<n; i++) {
        map[i] = new int[m]();
        count[i] = new int[m]();
        visited[i] = new bool[m]();
        for (int j=0; j<m; j++) {
            count[i][j] = -1;
            cin >> map[i][j];
            if (map[i][j] == 1) {
                count[i][j] = 0;
                visited[i][j] = true;
                q.push({i, j});
            }
        }
    }
    bfs(map, count, visited, n, m, q);
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (count[i][j] > max) {
                max = count[i][j];
            }
            if (map[i][j] != -1 && count[i][j] == -1) {
                cout << -1;
                delete[] map;
                delete[] count;
                return 0;
            }
        }
    }
    cout << max;
    delete[] map;
    delete[] count;
    return 0;
}
