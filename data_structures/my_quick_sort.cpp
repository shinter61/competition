#include <iostream>
#include <vector>

using namespace std;

template<typename T>
void printVector(const vector<T> &vec) {
    for (auto &i : vec) {
        cout << i << "; ";
    }
    cout << endl;
}

template<typename T>
size_t divideVec(vector<T> &vec, size_t start, size_t end) {
  T pivot = vec.at(start);
  auto lh = start + 1;
  auto rh = end;
  while(true) {
    while(lh < rh && vec.at(rh) >= pivot) { rh -= 1; }
    while(lh < rh && vec.at(lh) < pivot) { lh += 1; }

    cout << "vec.at(lh) "  << vec.at(lh) << endl;
    cout << "vec.at(rh) "  << vec.at(rh) << endl;

    if (lh == rh) break;

    T tmp = vec.at(lh);
    vec.at(lh) = vec.at(rh);
    vec.at(rh) = tmp;

    printVector(vec);
  }

  if (vec.at(lh) >= pivot) return start;
  vec.at(start) = vec.at(lh);
  vec.at(lh) = pivot;

  return lh;
}

template<typename T>
void sort(vector<T> &vec, size_t start, size_t end) {
  if (start >= end) return;

  auto boundary = divideVec(vec, start, end);
  cout << "boundary " << boundary << endl;
  sort(vec, start, boundary);
  sort(vec, boundary + 1, end);
}

template<typename T>
void quickSort(vector<T> &vec) {
  sort(vec, 0, vec.size() - 1);
}

int main() {
  vector<int> vec1 = { 43, 5, 123, 94, 359, -23, 2, -1 };

  printVector(vec1);
  quickSort(vec1);
  printVector(vec1);

  return EXIT_SUCCESS;
}
