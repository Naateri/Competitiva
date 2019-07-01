#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	unsigned long long n, k, A, B;
	unsigned long long x, sum = 0;
	cin >> n;
	cin >> k;
	cin >> A;
	cin >> B;
	x = n;
	while (x > 1){
		if (x % k == 0){
			if (B < A){
				x = x/k;
				sum += B;
			} else {
				x--;
				sum += A;
			}
		} else {
			x--;
			sum += A;
		}
	}
	cout << sum << endl;
	return 0;
}

