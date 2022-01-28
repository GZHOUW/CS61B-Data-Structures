#include <iostream>
#include <vector>
using namespace std;

vector<int> merge(vector<int> a, vector<int> b) {
	vector<int> merged;
	int p_a = 0, p_b = 0;
	while (p_a < a.size() and p_b < b.size()) {
		if (a[p_a] < b[p_b]) {
			merged.push_back(a[p_a]);
			p_a++;
		}
		else {
			merged.push_back(b[p_b]);
			p_b++;
		}
	}
	// add remaining numbers to merged
	while (p_a < a.size()) {
		merged.push_back(a[p_a]);
		p_a++;
	}
	while (p_b < b.size()) {
		merged.push_back(b[p_b]);
		p_b++;
	}
	return merged;
}


vector<int> mergeSort(vector<int> a) {
	int n = a.size();
	if (n == 1) {
		return a;
	}

	vector<int> left = vector<int>(a.begin(), a.begin() + n / 2);
	vector<int> right = vector<int>(a.begin() + n / 2, a.end());

	vector<int> left_sorted = mergeSort(left);
	vector<int> right_sorted = mergeSort(right);

	return merge(left_sorted, right_sorted);
}