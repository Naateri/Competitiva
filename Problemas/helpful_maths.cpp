#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <sstream>

using namespace std;

//Solution to the Helpful maths problem
//http://codeforces.com/contest/339/problem/A

string intToString(const int &z) {
	stringstream leString;
	leString << z;
	return leString.str();
}

int stringToInt(string a){
	int ret;
	stringstream convi(a);
	convi >> ret;
	return ret;
}

void counting_sort(vector<int>& A, int k = 4){
	vector<int> counts (k);
	int temp;
	fill(counts.begin(), counts.end(), 0);
	for (int i = 0; i < A.size(); i++){
		counts.at(A.at(i))++;
	}
	A.clear();
	for (int i = 0; i < k; i++){
		temp = counts.at(i);
		for(int j = 0; j < temp; j++){
			A.push_back(i);
		}
	}
}

void fill_vec(vector<int>& A, string sum){
	string num;
	int temp;
	for (int i = 0; i < sum.size(); i++){
		if (sum[i] == '+') continue;
		num = sum[i];
		temp = stringToInt(num);
		A.push_back(temp);
	}
}

string fill_str(vector<int> A){
	string ret;
	for (int i = 0; i < A.size(); i++){
		ret += intToString(A.at(i));
		ret += '+';
	}
	ret.erase(ret.begin() + ret.size() - 1, ret.begin() + ret.size());
	return ret;
}

int main(int argc, char *argv[]) {
	vector<int> A;
	string sum;
	cin >> sum;
	fill_vec(A, sum);
	counting_sort(A);
	cout << fill_str(A);
	return 0;
}

