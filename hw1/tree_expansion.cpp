#include <iostream>
using namespace std;

//tree expansion

int main(int argc, char *argv[]) {
	int nh, m, res, offset, temp;
	cout << "Input: number of childs per node, then desired path length.\n";
	cin >> nh >> m; //number of children and length of path
	int* dp = new int[m];
	dp[0] = 1;
	offset = res = 0;
	//if there is only one child, amount of possible paths is (for m=1,2,3...): 1 1 2 4 7 11 16 ...
	//if there is two, amount of possible paths for the second branch is (for m=1,2,3...): 0 1 1 2 4 7 11 16 ...
	//if there is three, amount of possible paths for the third branch is (for m=1,2,3...): 0 0 1 1 2 4 7 11 ...
	//and so on, so we just need to sum all possible paths for each branch at m
	for(int i = 1; i < m; i++, offset++){ //building array with the values
		dp[i] = dp[i-1] + offset;
	}
	
	temp = m-1; //so it starts at the end of the array
	while(nh > 0 && temp >= 0){ 
		res += dp[temp--];
		nh--;
	}
	
	cout << "Paths that have length " << m << ": " << res << endl;
	
	return 0;
}

