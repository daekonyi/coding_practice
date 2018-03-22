#include <vector>
#include <iterator>
#include <iostream>
#include <tuple>

using namespace std;

int max_knapsack(const vector<pair<int, int>>& items, int max_weight) {
	vector<vector<int>> results(items.size(), vector<int>(max_weight+1, 0));

	// initialize first row (zero items) to zero for easier corner case handling
	for(int i=0; i<=max_weight; ++i) {
		results[0][i] = 0;
	}
	for (int i=1; i<items.size(); i++) {
		for (int j=0; j<=max_weight; ++j) {
			int weight = items[i].first;
			int value = items[i].second;
			if (j < weight) {
				results[i][j] = results[i-1][j];
			}
			else {
				int left_over = j - weight;
				results[i][j] = max( value + results[i-1][j-weight], results[i-1][j] );
			}
		}
		for (const auto& a : results) {
			copy (begin(a), end(a), ostream_iterator<int>(cout, " "));
			cout << endl;
		}
		cout << endl;
	}

	return 0;
}

int main(int argc, char **argv) {
	int num_items;
	int weight;
	int value;
	vector<pair<int, int>> items;
	cin >> num_items;
	items.emplace_back(make_pair(0, 0));
	for (int i=0; i<num_items; ++i) {
		cin >> weight >> value;
		items.emplace_back(make_pair(weight, value));
	}	
	max_knapsack(items, 7);
	
	return 0;
}
