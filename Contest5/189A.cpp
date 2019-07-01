#include <iostream>
using namespace std;

int max_count = -1;
int n, a, b, c;

void dfs(int cur, int count){
	int cur_a, cur_b, cur_c;
	cur_a = cur - a;
	cur_b = cur - b;
	cur_c = cur - c;
	if (cur_a > 0){
		dfs(cur_a, count+1);
	}
	if (cur_b > 0){
		dfs(cur_b, count+1);
	}
	if (cur_c > 0){
		dfs(cur_c, count+1);
	}
	
	if (cur_a == 0){
		if (count > max_count){
			max_count = count;
			return;
		}
	}
	if (cur_b == 0){
		if (count > max_count){
			max_count = count;
			return;
		}
	}
	if (cur_c == 0){
		if (count > max_count){
			max_count = count;
			return;
		}
	}
	
	return; 
}

int main(int argc, char *argv[]) {
	cin >> n >> a >> b >> c;
	dfs(n,1);
	cout << max_count << endl;
	return 0;
}

