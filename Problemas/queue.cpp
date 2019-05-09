#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct FenwickTree{
	int size;
	int* fenwick;
	FenwickTree(int size){
		this->size = size;
		fenwick = new int[size+1](); //all 0's
	}
	int getSum(int x){
		int sum = 0, cur_index = x+1;
		while (cur_index > 0){
			sum += fenwick[cur_index];
			cur_index = cur_index - (cur_index & (-cur_index));
		}
		return sum;
	}
	int update(int x, int val){
		int cur_index = x+1;
		while (cur_index <= this->size){
			fenwick[cur_index] += val;
			cur_index = cur_index + (cur_index & (-cur_index));
		}
	}
	int range_sum(int start, int end){
		return getSum(end) - getSum(start-1);
	}
};


int main(int argc, char *argv[]) {
	vector<int> times;
	int n, total = 1, sum = 0;
	cin >> n;
	times.resize(n);
	for(int i = 0; i < n; i++){
		cin >> times[i];
	}
	sort(times.begin(), times.end());
	FenwickTree sums(n);
	for(int i = 0; i < n; i++){
		sums.update(i, times[i]);
	}
	for(int i = 1; i < n; i++){
		//cout << "getSum(i-1) " << sums.getSum(i-1) << ", times[i] " << times[i] << endl;
		if (sums.getSum(i-1) <= times[i]){
			total++;
		} else {
			//cout << "Got bored, removing " << times[i] << "time.\n";
			sums.update(i, -times[i]);
			times[i] = 0;
		}
	}
	cout << total << endl;
	return 0;
}

