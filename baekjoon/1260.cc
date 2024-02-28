#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void dfs(vector<vector<int>> edges, bool *visited, int v) {
    cout << v << ' ';
    vector<int>::iterator iter;
    visited[v] = true;
    for (iter = edges[v].begin(); iter != edges[v].end(); iter ++) {
        if (visited[*iter]) {
            continue;
        }
        dfs(edges, visited, *iter);
    }
}

void bfs(vector<vector<int>> edges, queue<int> q, int v, int n) {
    bool *visited = new bool[n+1]();
    q.push(v);
    visited[v] = true;
    vector<int>::iterator iter;
    while (!q.empty()) {
        cout << q.front() << ' ';
        int front = q.front();
        q.pop();
        for (iter = edges[front].begin(); iter != edges[front].end(); iter ++) {
            if (visited[*iter]) {
                continue;
            }
            visited[*iter] = true;
            q.push(*iter);
        }
    }
    delete[] visited;
}

int main() {
    int n, m, v, start, end;
    cin >> n >> m >> v;
    vector<vector<int>> edges(n + 1);
    for (int i=0; i < m; i++) {
        cin >> start >> end;
        edges.at(start).push_back(end);
        edges.at(end).push_back(start);
    }
    for (int i=0; i <= n; i++) {
        sort(edges.at(i).begin(), edges.at(i).end());
    }

    bool *visited = new bool[n+1]();
    dfs(edges, visited, v);
    cout << '\n';
    queue<int> q;
    bfs(edges, q, v, n);
    delete[] visited;
    return 0;
}
