#include <iostream>
#include <string>
#include <vector>
using namespace std;

//solution to the bit++ codeforces problem
//http://codeforces.com/contest/282/problem/A

int get_value(vector<string> operations, int n){
	int x = 0;
	for (int i = 0; i < n; i++){
		if  ( (operations.at(i).at(1)) == '+' ) x += 1;
		else x -= 1;
	}
	return x;
}

int main(int argc, char *argv[]) {
	short n;
	vector<string> operations (150);
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> operations.at(i);
	}
	cout << get_value(operations, n);
	return 0;
}

