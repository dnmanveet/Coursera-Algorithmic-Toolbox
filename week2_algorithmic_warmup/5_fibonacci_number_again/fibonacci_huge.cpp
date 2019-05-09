#include <iostream>

long long get_fibonacci_huge_naive(long long n, long long m) {
    long long F[n + 1];
    F[0] = 0;
    F[1] = 1;
    for (int i = 2; i < n + 1; ++i)
    {
        F[i] = (F[i - 1]) + (F[i - 2]);
    }

    return F[n] % m;
}

int main() {
    long long n, m;
    std::cin >> n >> m;
    std::cout << get_fibonacci_huge_naive(n, m) << '\n';
}
