#include <iostream>
#include <bitset>
#include <string>

#define M 32

using namespace std;

bool count_1s(string num, int h){
	int cur = 0;
	for (int i = 0; i < num.size(); i++){
		if (num[i] == '1') cur++;
	}
	return h == cur;
}

int main(int argc, char *argv[]) {
	unsigned long datasets, n, h;
	string num;
	
	cin >> datasets;
	for(int i = 0; i < datasets; i++){
		cin >> n >> h;
		for(int j = 1; j < ( 1 << n ); j++ ){
			bitset<16> b(j);
			num = b.to_string();
			if (count_1s(num, h)) cout << num.substr(num.size() - n , num.size()) << endl;
		}
		cout << endl;
	}
	return 0;
}

