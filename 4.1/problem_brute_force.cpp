#include <iostream>
#include <cmath>

using namespace std;

int Parity(unsigned long param) {
	int result = 0;
	while (param) {
		result ^= (param & 1);
		param >>= 1;
	}
	return result;
}

int main(int argc, char **argv) {
	if (argc == 2) {
		cout << Parity(stoi(argv[1])) << endl;
	}
	return 0;

}
