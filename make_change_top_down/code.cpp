#include <iostream>
#include <vector>
#include <unordered_map>
#include <iterator>

using namespace std;


int MakeChange(int amount, const vector<int> &denominations, int index, unordered_map<string, int> *memo_ptr) {
	unordered_map<string, int> &memo = *memo_ptr;
	if (amount == 0) {
		return 1;
	}
	if (index >= denominations.size()) {
		return 0;
	}
	string key = to_string(amount) + "-" + to_string(index);
	auto iter = memo.find(key);
	if (iter != memo.end()) {
		return iter->second;
	}
	int amount_with_coins = 0;
	int ways = 0;
	while (amount_with_coins <= amount) {
		int remaining = amount - amount_with_coins;
		ways += MakeChange(remaining, denominations, index + 1, &memo);
		amount_with_coins += denominations[index];		
	}
	memo[key] = ways;
	return ways;
}

int MakeChange(int amount, const vector<int>& denominations) {
	unordered_map<string, int> memo;
	return MakeChange(amount, denominations, 0, &memo);
}

int main(int argc, char **argv) {
	int amount;
	cin >> amount;
	int num_denominations;
	cin >> num_denominations;
	vector<int> denominations(num_denominations);
	for (int i=0; i<num_denominations; ++i) {
		int denomination;
		cin >> denomination;
		denominations.emplace_back(denomination);
	}	
	cout << "Number of ways: " << MakeChange(amount, denominations) << endl;
	return 0;
}
