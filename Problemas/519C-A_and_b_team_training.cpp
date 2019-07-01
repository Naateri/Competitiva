#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	int n, m;
	cin >> n >> m; //experienced, newbies
	int ans = 0;
	while (n > 0 && m > 0){
		if (--n >= 0){
			if (m - 2 >= 0){
				ans++;
				m -= 2;
			} else if (--n >= 0 && m - 1 >= 0){
				ans++;
				m--;
			}
		}
	}
	cout << ans << endl;
	return 0;
}

