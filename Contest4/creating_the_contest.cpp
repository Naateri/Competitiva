#include <iostream>
#include <vector>
using namespace std;

vector<int> difs;
int valores[200000] = {0};
vector<int> cur_solution;

int cont_max = 1, cont = 1;

int main(int argc, char *argv[]) {
	int n, a;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a;
		difs.push_back(a);
	}
	
	for(int i = 0; i < n-1; i++){
		
		if (cont > cont_max) cont_max = cont;	
			
		if (difs[i] << 1 >= difs[i+1]){
			cont++;
		} else {
			cont = 1;
		}
		//if (cur_solution.size() > max_num) max_num = cur_solution.size();
	}
	
	if (cont > cont_max) cont_max = cont;	
	
	cout << cont_max << endl;
	
	return 0;
}

