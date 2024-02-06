#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct User {
  int idx;
  int w;
  int h;
  int rank;
};

bool compareWeight(User u1, User u2) {
  return u1.w > u2.w;
}

bool compareHeight(User u1, User u2) {
  return u1.h > u2.h;
}
bool compareIndex(User u1, User u2) {
  return u1.idx < u2.idx;
}
bool compareRank(User u1, User u2) {
  return u1.rank < u2.rank;
}

int main() {
  int n, w, h;
  vector<User> usersW, usersH;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> w >> h;
    usersW.push_back({i, w, h, 0});
  }

  usersH = usersW;

  stable_sort(usersW.begin(), usersW.end(), compareWeight);
  stable_sort(usersH.begin(), usersH.end(), compareHeight);

  for (vector<User>::iterator i = usersW.begin(); i != usersW.end(); ++i) {
    vector<User> tempW;
    vector<User> tempH;
    for (vector<User>::iterator j = usersW.begin(); j != usersW.end(); ++j) {
      if (i->idx == j->idx || i->w >= j->w) {
        break;
      }
      tempW.push_back(*j);
      
    }
    for (vector<User>::iterator k = usersH.begin(); k != usersH.end(); ++k) {
      if (i->idx == k->idx || i->h >= k->h) {
        break;
      }
      tempH.push_back(*k);
      
    }
    sort(tempW.begin(), tempW.end(), compareIndex);
    sort(tempH.begin(), tempH.end(), compareIndex);
    vector<User> intersection;
    set_intersection(tempW.begin(), tempW.end(), tempH.begin(), tempH.end(), back_inserter(intersection), compareIndex);
    i->rank = intersection.size();
  }


  stable_sort(usersW.begin(), usersW.end(), compareIndex);
  for (vector<User>::iterator i = usersW.begin(); i != usersW.end(); ++i) {
    cout << i->rank + 1 << " ";
  }


  return 0;
}