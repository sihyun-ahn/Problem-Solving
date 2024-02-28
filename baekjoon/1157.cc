#include <iostream>
#include <map>
#include <cctype>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    map<char, int> dict;
    int max = 0;
    char maxChar;
    string s;
    cin >> s;

    for (int i=0; i<s.size(); i++) {
        dict[tolower(s[i])] ++;
    }

    for (auto iter = dict.begin(); iter != dict.end(); iter ++) {
        if (iter->second > max) {
            max = iter->second;
            maxChar = iter->first;
        } else if (iter->second == max) {
            maxChar = '?';
        }
    }

    cout << (char)toupper(maxChar);

    return 0;
}