#include <vector>
#include <iostream>
#include <iterator>

using namespace std;

template <typename T>
void LongestIncreasingSubsequence(const vector<T> &vec) {
	if (!vec.size()) {
		return;
	}
	vector<vector<T>> dp_vec(vec.size());
	dp_vec[0].emplace_back(vec[0]);
	for (int i=1; i<vec.size(); ++i) {
		for (int j=0; j<i; ++j) {
			if ((vec[i] > vec[j]) && (dp_vec[j].size()+1 > dp_vec[i].size())) {
				dp_vec[i] = dp_vec[j];
			}
		}	
		dp_vec[i].emplace_back(vec[i]);
	}
	
	for (const auto &a : dp_vec) {
		copy(begin(a), end(a), ostream_iterator<T>(cout, " "));
		cout << endl;
	}
}

int main(int argc, char **argv) {
	vector<int> numbers;
	int val;
	while (cin >> val) {
		numbers.emplace_back(val);
	}
	LongestIncreasingSubsequence(numbers);
	return 0;
}
