#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
using namespace std;

int chic_score(vector<vector<int>> dist, vector<int> colm) {
    vector<vector<int>>::iterator itor;
    vector<int>::iterator itor_colm;
    int score = 0;

    for (itor = dist.begin(); itor != dist.end(); itor ++) {
        vector<int> cand;
        for (itor_colm = colm.begin(); itor_colm != colm.end(); itor_colm ++) {
            cand.push_back((*itor)[(*itor_colm)]);
        }
        score += *min_element(cand.begin(), cand.end());
    }
    return score;
}

void combination(vector<vector<int>> &dist, vector<int> &scores, vector<int> arr, vector<int> comb, int r, int index, int depth) {
    if (r == 0) {
        scores.push_back(chic_score(dist, comb));
        return;
    }
    else if (depth == arr.size()) return;
    comb[index] = arr[depth];
    combination(dist, scores, arr, comb, r - 1, index + 1, depth + 1);
    combination(dist, scores, arr, comb, r, index, depth + 1);
}

int main() {
    int n, m, cnt = 0;
    cin >> n >> m;
    char **map = new char*[n];
    vector<array<int, 2>> house_map;
    vector<array<int, 2>> chicken_map;
    vector<int> chicken_idx;
    vector<int> scores;
    vector<int> comb(m);

    for (int i=0; i<n; i++) {
        map[i] = new char[n];
        for (int j=0; j<n; j++) {
            cin >> map[i][j];
            if (map[i][j] == '1') {
                house_map.push_back({i, j});
            } else if (map[i][j] == '2') {
                chicken_map.push_back({i, j});
                chicken_idx.push_back(cnt);
                cnt ++;
            }
        }
    }
    int houses = house_map.end() - house_map.begin();
    vector<vector<int>> dist(houses);

    // discard chickens - m
    vector<array<int, 2>>::iterator itor, itor_inner;
    int i = 0;
    int housex, housey, chicx, chicy;
    for (itor = house_map.begin(); itor != house_map.end(); itor ++) {
        housex = (*itor)[0];
        housey = (*itor)[1];
        for (itor_inner = chicken_map.begin(); itor_inner != chicken_map.end(); itor_inner ++) {
            chicx = (*itor_inner)[0];
            chicy = (*itor_inner)[1];
            int temp = abs(housex - chicx) + abs(housey - chicy);
            dist.at(i).push_back(temp);
        }
        i++;
    }

    // combination -> pass to chic_score func
    combination(dist, scores, chicken_idx, comb, m, 0, 0);

    cout << *min_element(scores.begin(), scores.end());

    delete[] map;
    return 0;
}
