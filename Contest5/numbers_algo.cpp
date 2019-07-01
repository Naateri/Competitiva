#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	int n, x, y;
	cin >> n;
	if (n & 1){
		x = 9; y = n-9;
	} else{
		x = 8; y = n-8;
	}
	
	cout << x << ' ' << y << endl;
	return 0;
}

