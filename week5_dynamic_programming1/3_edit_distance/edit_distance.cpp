#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using std::string;
using std::vector;

int edit_distance(const string &str1, const string &str2) {
  //write your code here
  	int a = str1.size();
	int b = str2.size();
	vector<vector<int> > disp(a + 1, vector<int>(b + 1, 0));
	for(int y = 0; y <= a; ++y) {
        disp[y][0] = y;
    }
    for(int z = 0; z <= b; ++z) {
        disp[0][z] = z;
    }
	int cal_cost = 0;
	for(int i = 1; i <= a; ++i) {
		for(int j = 1; j <= b; ++j) {
			if(str1[i-1] == str2[j-1])
				cal_cost = 0;
			else
				cal_cost = 1;
			disp[i][j] = std::min(std::min(disp[i-1][j],disp[i][j-1]) + 1, disp[i-1][j-1] + cal_cost);
		}
	}
	return disp[a][b];
}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}
