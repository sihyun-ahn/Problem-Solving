#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int out = 0;

void
dfs(int target_node, vector<vector<int>> &network, bool *visited) {
  vector<int>& target_vec = network[target_node];
  visited[target_node] = true;
  out ++;
  for (vector<int>::iterator iter = target_vec.begin(); iter != target_vec.end(); iter ++) {
    if (visited[*iter]) continue;
    dfs(*iter, network, visited);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, p, from, to;
  cin >> n >> p;

  vector<vector<int>> network(n + 1);
  bool *visited = new bool[n + 1]();

  for (int i=0; i<p; i++) {
    cin >> from >> to;
    network[from].push_back(to);
    network[to].push_back(from);
  }

  for (int i=0; i <= n; i++) {
    sort(network.at(i).begin(), network.at(i).end());
  }

  dfs(1, network, visited);

  cout << out - 1;
  return 0;
}