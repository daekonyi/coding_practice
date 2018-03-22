#include <random>
#include <iostream>

using namespace std;

int main(int argc, char **argv) {
	random_device rd;
	default_random_engine engine(rd());
	uniform_int_distribution<int> dist(0, 10);
	
	for (int i=0; i<16; ++i) {
		cout << dist(engine) << endl;
	}
	return 0;
}
