#include <iostream>
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

void print_array(int* arr, int size){
	for (int i = 0; i < size; i++){
		cout << *(arr+i) << ", ";
	}
	cout << endl;
}

int main(int argc, char *argv[]) {
	int A[] = {4,2,9,8,1,5};
	FenwickTree Fenwick(6);
	for (int i = 0; i < 6; i++){
		Fenwick.update(i,A[i]);
		print_array(Fenwick.fenwick, Fenwick.size+1);
	}
	//cout << Fenwick.getSum(4) - Fenwick.getSum(1) << endl;
	cout << Fenwick.range_sum(2,4) << endl;
	//cout << Fenwick.getSum(2) << endl;
	return 0;
}

