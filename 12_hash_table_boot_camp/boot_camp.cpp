#include <unordered_map>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

vector<vector<string>> FindAnagrams(const vector<string>& words) {
	unordered_map<string, vector<string>> anagrams;
	for (const auto& a : words) {
		string sorted_word(a);
		sort(begin(sorted_word), end(sorted_word));
		anagrams[sorted_word].emplace_back(a);
	}
	vector<vector<string>> ret;
	for (const auto& a : anagrams) {
		ret.emplace_back(a.second);
	}
	return ret;
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
		auto anagram_list = FindAnagrams(v);
		cout << "Anagrams: " << endl;
		for (auto a : anagram_list) {
			copy (begin(a), end(a), ostream_iterator<string>(cout, " "));
			cout << endl;
		} 

	}
	return 0;
}
