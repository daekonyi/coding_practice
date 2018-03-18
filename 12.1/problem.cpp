#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

vector<string> FindPalindromes(const vector<string>& words) {
	vector<string> palindromes;
	palindromes.reserve(words.size());
	for (const auto& word : words) {
		unordered_set<char> odd_frequency;
		for (const auto& letter : word) {
			if (odd_frequency.count(letter)) {
				odd_frequency.erase(letter);
			}
			else {
				odd_frequency.emplace(letter);
			}
		}
		if (odd_frequency.size() == 1) {
			palindromes.emplace_back(word);
		}
	}
	return palindromes;
}

int main(int argc, char **argv) {
	if (argc == 2) {
		ifstream ifs(argv[1]);
		string str;
		vector<string> v;
		while (ifs >> str) {
			v.emplace_back(str);
		}
		cout << "Original Words: " << endl;
		copy (begin(v), end(v), ostream_iterator<string>(cout, " "));
		cout << endl;
		auto palindromes = FindPalindromes(v);
		cout << "Palindromes: " << endl;
		copy (begin(palindromes), end(palindromes), ostream_iterator<string>(cout, " "));

	}
	return 0;
}
