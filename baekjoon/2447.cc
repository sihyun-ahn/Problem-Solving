#include <iostream>
#include <vector>
using namespace std;


void rec(int n, int row, vector<vector<char>>& stars) {
    if (n == 3) {
        for (int i=0; i<3; i++) {
            stars.at(row).push_back('*');
        }
        stars.at(row + 1).push_back('*');
        stars.at(row + 1).push_back(' ');
        stars.at(row + 1).push_back('*');
        for (int i=0; i<3; i++) {
            stars.at(row + 2).push_back('*');
        }
    } else {
        for (int i = 0; i < 3; i++) {
            rec(n/3, row, stars);
        }
        rec(n/3, row + n/3, stars);
        for (int i = n/3; i < n/3 * 2; i++) {
            for (int j = n/3; j < n/3 * 2; j++) {
                stars.at(row + j).push_back(' ');
            }
        }
        rec(n/3, row + n/3, stars);
        for (int i = 0; i<3; i++) {
            rec(n/3, row + n/3 * 2, stars);
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<vector<char>> stars(n);

    rec(n, 0, stars);

    vector<vector<char>>::iterator row;
    vector<char>::iterator col;
    for (row = stars.begin(); row != stars.end(); row++) {
        for (col = row->begin(); col != row->end(); col++) {
            cout << *col;
        }
        cout << "\n";
    }

    return 0;
}
