#include <iostream>
#include <set>

using namespace std;

int main() {
  set<int> s;
  s.insert(3);
  cout << s.size() << endl;
  s.insert(1);

  for (auto i = s.begin(); i != s.end(); i++) cout << *i << ", ";
  cout << endl;

  s.erase(100);
  for (auto i = s.begin(); i != s.end(); i++) cout << *i << ", ";
  cout << endl;

  s.insert(5);
  auto itr = s.find(3);
  cout << *itr << endl;

  s.clear();
  cout << s.size() << endl;

  return EXIT_SUCCESS;
}
