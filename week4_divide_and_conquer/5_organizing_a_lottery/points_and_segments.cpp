#include <iostream>
#include <vector>

using std::vector;

long long get_inversions(vector<int> &a, vector<int> &b, size_t left, int ave, size_t right) {
    size_t l = left, j = ave, k = left;
    long long inverse_counter = 0;
    while (l <= ave - 1 && j <= right) {
        if (a[l] <= a[j]) {
            b[k] = a[l];
            l++;
        } else {
            b[k] = a[j];
            inverse_counter += ave - l;
            j++;
        }
        k++;
    }
    while (l <= ave - 1) {
        b[k] = a[l];
        l++;
        k++;
    }
    while (j <= right) {
        b[k] = a[j];
        j++;
        k++;
    }
    for (l = left; l <= right; l++) {
        a[l] = b[l];
    }
    return inverse_counter;
}

long long merge_sort(vector<int> &a, vector<int> &b, size_t left, size_t right) {
    long long inverse_counter = 0;
    if (right <= left) return inverse_counter;
    size_t ave = left + (right - left) / 2;
    inverse_counter += merge_sort(a, b, left, ave);
    inverse_counter += merge_sort(a, b, ave + 1, right);
    inverse_counter += get_inversions(a, b, left, ave + 1, right);
    return inverse_counter;
}

int main() {
    int n;
    std::cin >> n;
    vector<int> a(n);
    for (size_t i = 0; i < a.size(); i++) {
        std::cin >> a[i];
    }
    vector<int> b(a.size());
    std::cout << merge_sort(a, b, 0, a.size() - 1) << '\n';
}

