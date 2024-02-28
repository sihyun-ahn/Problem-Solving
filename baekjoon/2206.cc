#include <iostream>
#include <vector>
#include <array>
#include <queue>
#include <algorithm>
using namespace std;



void bfs(char **map, int n, int m) {
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {1, -1, 0, 0};
    int res;
    array<int, 3> front;    // x, y, broke
    queue<array<int, 3>> q;
    int **countNBroke = new int*[n];
    int **countBroke = new int*[n];
    int **visited = new int*[n];
    for (int i=0; i<n; i++) {
        countNBroke[i] = new int[m]();
        countBroke[i] = new int[m]();
        visited[i] = new int[m]();
    } 
    countNBroke[0][0] = 1;
    countBroke[0][0] = 1;
    visited[0][0] = 3;
    q.push({0, 0, 0});

    while (!q.empty()) {
        front = q.front();
        q.pop();
        for (int i=0; i<4; i++) {
            int newX = front[0] + dx[i];
            int newY = front[1] + dy[i];
            if (newX >= 0 && newX < n && newY >= 0 && newY < m && visited[newX][newY] < 3) {
                // move to wall
                if (map[newX][newY] == '1') {
                    if (front[2] == 0 && visited[newX][newY] <= 1) {
                        q.push({newX, newY, 1});
                        countBroke[newX][newY] = countNBroke[front[0]][front[1]] + 1;
                        visited[newX][newY] = 3;
                    }
                } 
                // move to non-wall
                else {
                    if (visited[newX][newY] == 0) {
                        q.push({newX, newY, front[2]});
                        if (front[2] == 0) {
                            countNBroke[newX][newY] = countNBroke[front[0]][front[1]] + 1;
                        } else {
                            countBroke[newX][newY] = countBroke[front[0]][front[1]] + 1;
                        }
                        visited[newX][newY] += front[2] + 1;
                    } else if ((visited[newX][newY] == 1 && front[2] == 1)){
                        q.push({newX, newY, front[2]});
                        countBroke[newX][newY] = countBroke[front[0]][front[1]] + 1;
                        visited[newX][newY] += 2;
                    } else if (visited[newX][newY] == 2 && front[2] == 0) {
                        q.push({newX, newY, front[2]});
                        countNBroke[newX][newY] = countNBroke[front[0]][front[1]] + 1;
                        visited[newX][newY] += 1;
                    }
                }       
            }
        }
    }

    if (countNBroke[n-1][m-1] != 0 && countBroke[n-1][m-1] != 0) {
        res = min({countNBroke[n-1][m-1], countBroke[n-1][m-1]});
    } else if (countNBroke[n-1][m-1] != 0) {
        res = countNBroke[n-1][m-1];
    } else if (countBroke[n-1][m-1] != 0) {
        res = countBroke[n-1][m-1];
    } else {
        res = -1;
    }
    cout << res;

    for (int i=0; i<n; i++) {
        delete[] countNBroke[i];
        delete[] countBroke[i];
        delete[] visited[i];
    } 
    delete[] countNBroke;
    delete[] countBroke;
    delete[] visited;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    vector<array<int, 2>>::iterator iter;
    cin >> n >> m;

    char **map = new char*[n];
    for (int i=0; i<n; i++) {
        map[i] = new char[m];
        for (int j=0; j<m; j++) {
            cin >> map[i][j];
        }
    }
    bfs(map, n, m);
    for (int i=0; i<n; i++) {
        delete[] map[i];
    } 
    delete[] map;
    return 0;
}
