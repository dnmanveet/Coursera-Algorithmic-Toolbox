#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <functional>
#define endl '\n'
using namespace std;

int KnapSack_amount(int W, vector<int> value, vector<int> wt, int num) {
	
	vector<vector<int>>  k_matrix(num + 1,vector<int>(W + 1));
	for (int a = 0; a <= num; a++) {
		for (int w = 0; w <= W; w++) {
			if (a == 0 || w == 0)
				k_matrix[a][w] = 0;
			else if (wt[a - 1] <= w)
				k_matrix[a][w] = max(value[a - 1] + k_matrix[a - 1][w - wt[a - 1]], k_matrix[a - 1][w]);
			else
				k_matrix[a][w] = k_matrix[a - 1][w];
		}
	}

	return k_matrix[num][W];
}

int main() {
	int num, Cap;
	cin >> Cap >> num;

	vector<int> Val(num);
	vector<int> Wt(num);
	int Temp;
	for (size_t a = 0; a < num; a++) {
		cin >> Temp;
		Val[a] = Wt[a] = Temp;
	}
	cout << KnapSack_amount(Cap, Val, Wt, num) << endl;
}
