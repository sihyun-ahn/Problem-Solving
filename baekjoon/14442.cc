#include <iostream>
#include <array>
#include <algorithm>
using namespace std;



int dfs(char **map, int **visited, int n, int m, int k, int broke, int x, int y, int count) {
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {1, -1, 0, 0};

    if (x == n - 1 && y == m - 1) {
        // cout << count;
        return count;
    }

    for (int i=0; i<4; i++) {
        int newX = x + dx[i];
        int newY = y + dy[i];
        
        // valid newX, newY
        if (newX >= 0 && newX < n && newY >= 0 && newY < m && visited[newX][newY] < 3) {
            // move to wall
            if (map[newX][newY] == '1') {
                cout << "wall: " << newX << ' ' << newY << ' ' << count << '\n';
                if (broke < k - 1 && visited[newX][newY] == 0) {
                    visited[newX][newY] = 3;
                    return dfs(map, visited, n, m, k, broke + 1, newX, newY, count + 1);
                }
            } 
            // move to non-wall
            else {
                if (visited[newX][newY] == 0) {
                    cout << "non-wall & visited 0: " << newX << ' ' << newY << ' ' << count << '\n';
                    visited[newX][newY] += (broke == 0) ? 1: 2;
                    return dfs(map, visited, n, m, k, broke, newX, newY, count++);                    
                } else if (visited[newX][newY] == 1 && broke > 0) {
                    cout << "non-wall & visited 1: " << newX << ' ' << newY << ' ' << count << '\n';
                    visited[newX][newY] += 2;
                    return dfs(map, visited, n, m, k, broke, newX, newY, count + 1); 
                } else if (visited[newX][newY] == 2 && broke == 0) {
                    cout << "non-wall & visited 2: " << newX << ' ' << newY << ' ' << count << '\n';
                    visited[newX][newY] ++;
                    return dfs(map, visited, n, m, k, broke, newX, newY, count + 1); 
                }
            }       
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, k;
    cin >> n >> m >> k;

    char **map = new char*[n];
    int **visited = new int*[n];
    for (int i=0; i<n; i++) {
        map[i] = new char[m];
        visited[i] = new int[m]();
        for (int j=0; j<m; j++) {
            cin >> map[i][j];
        }
    }

    cout << dfs(map, visited, n, m, k, 0, 0, 0, 1) << '\n';

    for (int i=0; i<n; i++) {
        delete[] map[i];
        delete[] visited[i];
    } 
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cout << visited[i][j] << ' ';
        }
        cout << '\n';
    } 
    delete[] map;
    delete[] visited;
    return 0;
}
