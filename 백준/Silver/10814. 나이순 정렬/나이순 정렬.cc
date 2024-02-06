#include <iostream>
#include <algorithm>

using namespace std;

struct User {
  int age;
  string name;
};

bool compare(User u1, User u2) {
  return u1.age < u2.age;
}


int main() {
  int n;
  cin >> n;
  User* users = new User[n];

  for (int i = 0; i < n; i++) {
    cin >> users[i].age >> users[i].name;
  }

  stable_sort(users, users + n, compare);

  for (int i = 0; i < n; i++) {
    cout << users[i].age << ' ' << users[i].name << '\n';
  }


  return 0;
}