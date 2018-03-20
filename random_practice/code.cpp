#include <random>
#include <iostream>

using namespace std;

int main(int argc, char **argv) {
	random_device rd;
	mt19937 mt(rd());
	uniform_int_distribution<int> dist(0, 10);
	
	for (int i=0; i<16; ++i) {
		cout << dist(mt) << endl;
	}
	return 0;
}
