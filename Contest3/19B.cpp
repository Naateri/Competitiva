#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
using namespace std;

int main(int argc, char *argv[]) {
	int n;
	pair<int, int> obj;
	vector<pair<int, int>> objs;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> obj.second >> obj.first;
		objs.push_back(obj);
	}
	sort(objs.begin(), objs.end());
	int t, s = 0;
	for(int i = 0; i < n; i++){
		t = objs[i].second;
		s += objs[i].first;
		if (t > 0){
//			t = objs[i].second--;
//			objs.erase(objs.end() - 1);
			n -= t;
		}
	}
	cout << s << endl;
	return 0;
}

