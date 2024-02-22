#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs(vector<vector<int>> path, queue<int> q, int s, int f, int *count) {
    q.push(s);
    count[s] = 0;
    vector<int>::iterator iter;
    while (!q.empty()) {
        int front = q.front();
        q.pop();
        for (iter = path[front].begin(); iter != path[front].end(); iter++) {
            if (count[*iter] == -1) {
                q.push(*iter);
                count[*iter] = count[front] + 1;
            }
        }
    }
}

int main() {
    int f, s, g, u, d;
    cin >> f >> s >> g >> u >> d;
    vector<vector<int>> path(f + 1);
    queue<int> q;
    int *count = new int[f + 1];
    for (int i=1; i<=f; i++) {
        count[i] = -1;
        if (i + u <= f) {
            path.at(i).push_back(i + u);
        }
        if (i - d > 0) {
            path.at(i).push_back(i - d);
        }
    }
    bfs(path, q, s, f, count);
    if (count[g] == -1) {
        cout << "use the stairs";
    } else {
        cout << count[g];
    }
    return 0;
}
