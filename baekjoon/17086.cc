#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int bfs(int **map, int x, int y, int n, int m) {
    int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
    int dy[] = {1, 1, 0, -1, -1, -1, 0, 1};
    queue<array<int, 2>> q;
    int **count = new int*[n];
    vector<int> step;
    for (int i=0; i<n; i++) {
        count[i] = new int[m]();
        for (int j=0; j < m; j++) {
            count[i][j] = -1;
        }
    }
    count[x][y] = 0;

    q.push({x, y});

    while (!q.empty()) {
        array<int, 2> front = q.front();
        q.pop();
        for (int i=0; i<8; i++) {
            if (front[0] + dx[i] >= 0 && front[0] + dx[i] < n && front[1] + dy[i] >= 0 && front[1] + dy[i] < m) {
                if (count[front[0] + dx[i]][front[1] + dy[i]] == -1) {
                    if (map[front[0] + dx[i]][front[1] + dy[i]] == 1) {
                        count[front[0] + dx[i]][front[1] + dy[i]] = count[front[0]][front[1]] + 1;
                        step.push_back(count[front[0] + dx[i]][front[1] + dy[i]]);
                    } else {
                        q.push({front[0] + dx[i], front[1] + dy[i]});
                        count[front[0] + dx[i]][front[1] + dy[i]] = count[front[0]][front[1]] + 1;
                    }
                }
            }
        }
    }

    return *min_element(step.begin(), step.end());
}

int main() {
    int n, m;
    cin >> n >> m;
    int **map = new int*[n];
    vector<int> step;
    
    for (int i=0; i < n; i ++) {
        map[i] = new int[m]();
        for (int j=0; j < m; j++) {
            cin >> map[i][j];
        }
    }

    for (int i=0; i < n; i ++) {
        for (int j=0; j < m; j++) {
            if (map[i][j] == 1) {
                step.push_back(0);
            } else {
                int temp = bfs(map, i, j, n, m);
                step.push_back(temp);
            }
        }
    }
    cout << *max_element(step.begin(), step.end());
    return 0;
}
