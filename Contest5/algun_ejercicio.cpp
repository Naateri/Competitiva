#include <iostream>
#include <vector>
using namespace std;

vector<int> lucky = {4, 7, 44, 47, 74, 77, 444, 447, 474, 477, 744, 747, 774, 777}; 

int main(int argc, char *argv[]) {
	
	int n;
	cin >> n;
	for (int i = 0; i < lucky.size(); i++){
		if (n % lucky[i] == 0){
			cout << "YES\n";
			return 0;
		}
	}
	cout << "NO\n";
	return 0;
}

