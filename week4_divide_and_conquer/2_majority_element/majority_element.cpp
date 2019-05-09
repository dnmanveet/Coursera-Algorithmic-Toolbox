#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

int get_majority_element(vector<int> &a, int left, int right) {
  if (left == right) return -1;
  if (left + 1 == right) return a[left];
  //write your code here
  sort(a.begin(), a.end());
  int counter = 1;
  int ele = -1;
  for(int i = 0; i < a.size(); i++) {
	  if(a[i] == ele) {
		  counter++;
	  }
	  else{
		  ele = a[i];
		  counter = 1;
	  }
	  if(counter > a.size()/2)
		  return 1;
  }
  return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';
}
