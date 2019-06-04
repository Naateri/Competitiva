#include <iostream>
#include <vector>
using namespace std;

void create_v(int n, vector<int>& v){
	v.clear();
	for(int i = 2; i <= n; i++) v.push_back(i);
}

int main(int argc, char *argv[]) {
	int n, m, city, index;
	bool ok;
	vector<int> josephus;
	
	while(1){
		cin >> n;
		if (n == 0) break;
		m = 2; //minimum jump
		while(1){
			create_v(n, josephus);
			ok = 1;
			index = (m-1) % (josephus.size());
			city = josephus.at(index);
			while (josephus.size() > 1){
				if (city == 2){
					ok = 0;
					break;
				}							
				josephus.erase(josephus.begin() + index);				
				index = (index + m - 1) % (josephus.size());
				city = josephus.at(index);
			}
			
			if (ok){
				cout << m << endl;
				break;
			}
			m++;
		}
	}
	return 0;
}

