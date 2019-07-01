#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	unsigned long long t, a, b;
	cin >> t;
	for (unsigned long long i = 0; i < t; i++){
		cin >> a >> b;
		if (a > b) cout << ">\n";
		else if (a < b) cout << "<\n";
		else cout << "=\n";
	}
	return 0;
}

