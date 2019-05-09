#include <iostream>
#include <vector>
#include <climits>

using std::vector;
vector<int> coin = {1 , 3 , 4};

int get_change(int m) {
  //write your code here
std::vector<int> tab(m + 1);

  tab[0] = 0;

  for (int a = 1; a <= m; a++)
    tab[a] = INT_MAX;

  for (int a = 1; a <= m; a++)
  {
    for (int b = 0; b < m; b++)
    {
      if (coin[b] <= a)
      {
        int sub = tab[a - coin[b]];
        if (sub != INT_MAX && sub + 1 < tab[a])
          tab[a] = sub + 1;
      }
    }
  }
  return tab[m];
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
