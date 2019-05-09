#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

vector<int> optimal_sequence(int n) {
  std::vector<int> sequence;
  while (n >= 1) {
    sequence.push_back(n);
    if (n % 3 == 0) {
      n /= 3;
    } else if (n % 2 == 0) {
      n /= 2;
    } else {
      n = n - 1;
    }
  }
  reverse(sequence.begin(), sequence.end());
  return sequence;
}

vector<int> dyn_seq(int n) {
 std::vector<int> sequence;
	std::vector<int>  arr(n+1);
	for(int i =1; i< arr.size(); i++){
		arr[i] = arr[i-1] + 1;
		if (i%2 == 0) 
			arr[i] = std::min(1 + arr[i/2], arr[i]);
		if (i%3 == 0) 
			arr[i] = std::min(1 + arr[i/3], arr[i]);
	}
	int i = n;
	while (i>1) {
		sequence.push_back(i);
		if (arr[i-1] == arr[i]-1)
			i = i-1;
		else if (i%2 == 0 && (arr[i/2] == arr[i]-1))
			i = i/2;
		else if (i%3 == 0 && (arr[i/3] == arr[i]-1))
			i = i/3;
	}
	sequence.push_back(1);
	reverse(sequence.begin(), sequence.end());
	return sequence;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> sequence = dyn_seq(n);
  std::cout << sequence.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i) {
    std::cout << sequence[i] << " ";
  }
}
