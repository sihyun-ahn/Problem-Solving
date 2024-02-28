#include <iostream>
#include <queue>
#include <array>
using namespace std;

void bfs(int r1, int c1, int r2, int c2, int n) {
    int dx[] = {-2, -2, 0, 0, 2, 2};
    int dy[] = {-1, 1, -2, 2, -1, 1};
    int **count = new int*[n];
    queue<array<int, 2>> q;
    for (int i=0; i<n; i++) {
        count[i] = new int[n]();
        for (int j=0; j<n; j++) {
            count[i][j] = -1;
        }
    }
    count[r1][c1] = 0;
    q.push({r1, c1});

    while (!q.empty()) {
        array<int, 2> front = q.front();
        q.pop();
        for (int i=0; i<6; i++) {
            if (front[0] + dx[i] >= 0 && front[0] + dx[i] < n && front[1] + dy[i] >= 0 && front[1] + dy[i] < n) {
                if (count[front[0] + dx[i]][front[1] + dy[i]] == -1) {
                    count[front[0] + dx[i]][front[1] + dy[i]] = count[front[0]][front[1]] + 1;
                    if (front[0] + dx[i] == r2 && front[1] + dy[i] == c2) {
                        cout << count[front[0] + dx[i]][front[1] + dy[i]];
                        return;
                    } else {
                        q.push({front[0] + dx[i], front[1] + dy[i]});
                    }
                }
            }            
        }
    }
    cout << -1;
    return;
}

int main() {
    int n, r1, c1, r2, c2;
    cin >> n >> r1 >> c1 >> r2 >> c2;
    bfs(r1, c1, r2, c2, n);
    return 0;
}
