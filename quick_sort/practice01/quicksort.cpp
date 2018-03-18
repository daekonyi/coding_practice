#include <fstream>
#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

// end is one past actual end
int Partition(int start, int end, vector<int> *v_ptr) {
	vector<int> &v = *v_ptr;
	int pivot_val = v[start];
	int less_index = start;
	int equal_index = start;
	int greater_index = end;
	while (equal_index < greater_index) {
		if (v[equal_index] < pivot_val) {
			swap(v[equal_index], v[less_index]);
			++equal_index;
			++less_index;
		}	
		else if (v[equal_index] == pivot_val) {
			++equal_index;
		}
		else {
			--greater_index;
			swap(v[equal_index], v[greater_index]);
		}
	}
	return equal_index;
}

void QuickSortHelper(int start, int end, vector<int> *v_ptr) {
	vector<int> &v = *v_ptr;
	int pivot = Partition(start, end, &v);
	if (pivot < end) {
		QuickSortHelper(start, pivot, &v);
		QuickSortHelper(pivot, end, &v);
	} 
}

void QuickSort(vector<int> *v_ptr) {
	vector<int> &v = *v_ptr;
	QuickSortHelper(0, v.size(), &v);
}


int main(int argc, char **argv) {
	vector<int> v;
	int x;
	while (cin >> x) {
		v.emplace_back(x);
	}
	copy(begin(v), end(v), ostream_iterator<int>(cout, " "));
	cout << endl << endl;
	QuickSort(&v);
	copy(begin(v), end(v), ostream_iterator<int>(cout, " "));
	


	return 0;
}
