#include <iostream>
using namespace std;

int sequence[200000] = {0};
int ones, twos;

void print(){
	int i = 0;
	while (sequence[i] != 0) cout << sequence[i++] << ' ';
	cout << endl;
}

int main(int argc, char *argv[]) {
	ones = twos = 0;
	int n; cin >> n;
	for(int i = 0; i < n; i++){
		cin >> sequence[i];
		if (sequence[i] == 1) ones++;
		else twos++;
	}
	if (ones == 0 || twos == 0){
		print();
		return 0;
	}
	int index = 0;
	sequence[index++] = 2; twos--;
	sequence[index++] = 1; ones--;
	while (twos-- > 0){
		sequence[index++] = 2;
	}
	while (ones-- > 0){
		sequence[index++] = 1;
	}
	print();
	return 0;
}

