#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template<typename T>
void printVector(const vector<T> &vec) {
    for (auto &i : vec) {
        cout << i << "; ";
    }
    cout << endl;
}

template<typename T>
T partitionVec(vector<T> &vec,  size_t start, size_t end) {
    T pivot = vec.at(start);
    auto lh = start + 1;
    auto rh = end;

    while (true) {
        while (lh < rh && vec.at(rh) >= pivot) rh--;
        while (lh < rh && vec.at(lh) < pivot) lh++;

        if (lh == rh) break;

        T tmp = vec.at(lh);
        vec.at(lh) = vec.at(rh);
        vec.at(rh) = tmp;
    }

    if (vec.at(lh) >= pivot) return start;
    vec.at(start) = vec.at(lh);
    vec.at(lh) = pivot;
    return lh;
}

template<typename T>
void sort(vector<T> &vec, size_t start, size_t end) {
    if (start >= end)
        return;

    auto boundary = partitionVec(vec, start, end);

    sort(vec, start, boundary);
    sort(vec, boundary + 1, end);
}

template<typename T>
void quickSort(vector<T> &vec) {
    sort(vec, 0, vec.size() - 1);
}

int main()
{
    vector<int> vec1 = { 43, 5, 123, 94, 359, -23, 2, -1 };

    printVector(vec1);
    quickSort(vec1);
    printVector(vec1);

    return EXIT_SUCCESS;
}
