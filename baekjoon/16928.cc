#include <iostream>
#include <queue>
using namespace std;

void bfs(int *map) {
    int front;
    int count[101] = {0};
    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        front = q.front();
        q.pop();
        for (int i=1; i<=6; i++) {
            if (front + i > 0 && front + i <= 100 && count[map[front + i]] == 0) {
                q.push(map[front + i]);
                count[map[front + i]] += count[front] + 1;
            }
        }
    }
    cout << count[100];
}

int main() {
    int n, m, s, f;
    cin >> n >> m;
    int map[101] = {0};
    for (int i=1; i<=100; i++) {
        map[i] = i;
    }
    for (int i=0; i<n+m; i++) {
        cin >> s >> f;
        map[s] = f;
    }

    bfs(map);

    return 0;
}
