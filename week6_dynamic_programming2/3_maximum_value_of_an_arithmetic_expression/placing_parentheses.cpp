#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <cmath>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <iomanip>
#include <assert.h>
#include <vector>
#include <cstring>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <set>
#include <complex>
#include <list>
#include <climits>
#include <cctype>
#include <bitset>
#include <numeric>
#include <array>
#include <tuple>
#include <stdexcept>
#include <utility>
#include <functional>
#include <locale>
#define  endl  '\n'

using namespace std;

using std::vector;
using std::string;
using std::max;
using std::min;

long long eval(long long a, long long b, char op) {
  if (op == '*') {
    return a * b;
  } else if (op == '+') {
    return a + b;
  } else if (op == '-') {
    return a - b;
  } else {
    assert(0);
  }
}

long long get_maximum_value(const string &exp) {
  //write your code here
  int length = exp.size();
	int Operands_count = (length + 1) / 2;

	long long Minimum[Operands_count][Operands_count];
	long long Maximum[Operands_count][Operands_count];

	memset(Minimum, 0, sizeof(Minimum));
	memset(Maximum, 0, sizeof(Maximum)); 
	for (int z = 0; z < Operands_count; z++) {

		Minimum[z][z] = stoll(exp.substr(2 * z, 1));
		Maximum[z][z] = stoll(exp.substr(2 * z, 1));
	}

	for (int a = 0; a < Operands_count - 1; a++) {
		for (int i = 0; i < Operands_count - a - 1; i++) {
			int j = i + a + 1;
			long long MinValue = LLONG_MAX;
			long long MaxValue = LLONG_MIN;

			for (int k = i; k < j; k++) {
				long long a = eval(Minimum[i][k], Minimum[k + 1][j], exp[2 * k + 1]);
				long long b = eval(Minimum[i][k], Maximum[k + 1][j], exp[2 * k + 1]);
				long long c = eval(Maximum[i][k], Minimum[k + 1][j], exp[2 * k + 1]);
				long long d = eval(Maximum[i][k], Maximum[k + 1][j], exp[2 * k + 1]);

				MinValue = min(MinValue, min(a, min(b, min(c, d))));
				MaxValue = max(MaxValue, max(a, max(b, max(c, d))));

			}
			Minimum[i][j] = MinValue;
			Maximum[i][j] = MaxValue;
		}
	}

	return Maximum[0][Operands_count - 1];
  return 0;
}

int main() {
  string s;
  std::cin >> s;
  std::cout << get_maximum_value(s) << '\n';
}
