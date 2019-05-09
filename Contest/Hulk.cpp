#include <iostream>
#include <cstring>
using namespace std;

string love = "I love that ";
string hate = "I hate that ";
string love_end = "I love it";
string hate_end = "I hate it";

int main(int argc, char *argv[]) {
	int n; 
	cin >> n;
	string result;
	for (int i = 1; i <= n; i++){
		if (i == n){
			if (i & 1) result += hate_end;
			else result += love_end;
		} else {
			if (i & 1) result += hate;
			else result += love;
		}
	}
	cout << result << endl;
	return 0;
}

