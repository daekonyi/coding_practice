#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

void DutchFlag(int pivot_index, vector<int>* v_ptr) {
	vector<int>& v = *v_ptr;
	int pivot = v[pivot_index];
	int less_index = 0;
	int equal_index = 0;
	int greater_index = v.size();
	while (equal_index < greater_index) {
		if (v[equal_index] < pivot) {
			swap(v[equal_index], v[less_index]);
			++equal_index;
			++less_index;
		}
		else if (v[equal_index] == pivot) {
			++equal_index;
		}
		else {
			--greater_index;
			swap(v[equal_index], v[greater_index]);
		}	
	}
}



int main(int argc, char **argv) {
	if (argc == 2) {
		ifstream ifs(argv[1]);
		int n;
		ifs >> n;
		int index;
		ifs >> index;
		vector<int> v(n);
		for (int i=0; i<n; ++i) {
			ifs >> v[i];
		}
		cout << "Original Vector:" << endl;
		copy(begin(v), end(v), ostream_iterator<int>(cout, " "));
		DutchFlag(index, &v);
		cout << "Modified Vector:" << endl;
		copy(begin(v), end(v), ostream_iterator<int>(cout, " "));
	}
	return 0;
}
