#include <iostream>
#include <queue>
#include <array>
#include <algorithm>
#include <vector>

using namespace std;

void bfs(int ***map, int ***count, bool ***visited, int n, int m, int h, queue<array<int, 3>> q) {
    int dx[6] = {0, 0, -1, 1, 0, 0};
    int dy[6] = {1, -1, 0, 0, 0, 0};
    int dz[6] = {0, 0, 0, 0, 1, -1};
    while (!q.empty()) {
        array<int, 3> front = q.front();
        q.pop();
        for (int i=0; i<6; i++) {
            int newZ = front[0] + dz[i];
            int newX = front[1] + dx[i];
            int newY = front[2] + dy[i];
            if (newZ >= 0 && newZ < h && newX >= 0 && newX < n && newY >=0 && newY < m && map[newZ][newX][newY] == 0 && !visited[newZ][newX][newY]) {   
                count[newZ][newX][newY] = (count[newZ][newX][newY] == -1) ? count[front[0]][front[1]][front[2]] + 1: min({count[newZ][newX][newY], count[front[0]][front[1]][front[2]] + 1});
                q.push({newZ, newX, newY});
                visited[newZ][newX][newY] = true;
            }
        }
    }
    return;
}

int main() {
    int m, n, h, max = -1;
    cin >> m >> n >> h;
    int ***map = new int**[h];
    int ***count = new int**[h];
    bool ***visited = new bool**[h];

    queue<array<int, 3>> q;
    for (int i=0; i<h; i++) {
        map[i] = new int*[n];
        count[i] = new int*[n];
        visited[i] = new bool*[n];      
        for (int j=0; j<n; j++) {
            map[i][j] = new int[m]();
            count[i][j] = new int[m]();
            visited[i][j] = new bool[m]();
            for (int k=0; k<m; k++) {
                count[i][j][k] = -1;
                cin >> map[i][j][k];
                if (map[i][j][k] == 1) {
                    count[i][j][k] = 0;
                    visited[i][j][k] = true;
                    q.push({i, j, k});
                }
            }
        }
    }
    
    bfs(map, count, visited, n, m, h, q);
    for (int i=0; i<h; i++)
    for (int j=0; j<n; j++) {
        for (int k=0; k<m; k++) {
            if (count[i][j][k] > max) {
                max = count[i][j][k];
            }
            if (map[i][j][k] != -1 && count[i][j][k] == -1) {
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
