#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    int count = 0;
    bool isWord = false;
    getline(cin, s);
    for (int i=0; i < s.size(); i++) {
        if (s[i] == ' ') {
            isWord = false;
        } else {
            if (!isWord) {
                count ++;
                isWord = true;
            }
        }
    }
    cout << count;
    return 0;
}
