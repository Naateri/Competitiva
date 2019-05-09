#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	int n, m, k, v;
	int** groups;
	int* sizes;
	cin >> n >> m;
	groups = new int*[m];
	sizes = new int[m];
	for (int i = 0; i < m; i++){
		cin >> sizes[i];
		groups[i] = new int[sizes[i]];
		for (int j = 0; j < sizes[i]; j++){
			cin >> groups[i][j];
		}
	}
	for (int i = 0; i < m; i++){
		if (sizes[i] == 1){
			cout << "YES" << endl;
			return 0;
		}
	}
	bool* _groups = new bool[m]();
	bool found;
	//for (int num = 1; num <= n; num++){
		for (int i = 0; i < m; i++){
			if (_groups[i]) continue;
			for (int j = 0; j < sizes[i]; j++){
				if (_groups[i]) continue;
				//if (nums[num-1]) continue;
				for (int num = 1; num <= n; num++){
					if (groups[i][j] == -num){
						_groups[i] = 1;
						break;
					}
				}
			}
			if (! _groups[i]){
				cout << "YES" << endl;
				return 0;
			}
		}
		//cout << "num: " << num << endl;
	//}
	cout << "NO" << endl;
	return 0;
}

