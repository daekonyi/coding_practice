#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

void CountLetters(const vector<string>& words, unordered_map<char, int>* letter_count_ptr) {
	unordered_map<char, int>& letter_count = *letter_count_ptr;
	for (const auto& word : words) {
		for (const auto& letter : word) {
			if (letter_count.count(letter)) {
				++letter_count[letter];
			}
			else {
				letter_count[letter] = 1;
			}
		}
	}

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
	
		cout << "Letter Count: " << endl;
		unordered_map<char, int> letter_count;
		CountLetters(v, &letter_count);
		for (const auto& a : letter_count) {
			cout << a.first << " : " << a.second << endl;
		}



	}
	return 0;
}
