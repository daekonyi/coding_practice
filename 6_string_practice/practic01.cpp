#include <string>
#include <iostream>
#include <iterator>
#include <fstream>

using namespace std;

int main(int argc, char **argv) {
	string s1("This is a test string!");
	string s1_rev(s1.rbegin(), s1.rend());
	cout << s1 << endl;
	cout << s1_rev << endl;
	return 0;
}
