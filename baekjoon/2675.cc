#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t, r;
    string s;
    vector<vector<char>> ss;
    vector<vector<char>>::iterator outerIter;
    vector<char>::iterator innerIter;
    cin >> t;
    for (int i=0; i<t; i++) {
        vector<char> v;
        ss.push_back(v);
        cin >> r >> s;
        for (int j=0; j<s.size(); j++) {
            for (int k=0; k<r; k++) {
                ss.at(i).push_back(s[j]);
            }
        }
    }
    for (outerIter = ss.begin(); outerIter != ss.end(); outerIter ++) {
        for (innerIter = (*outerIter).begin(); innerIter != (*outerIter).end(); innerIter ++) {
            cout << *innerIter;
        }
        cout << '\n';
    }
    return 0;
}
