#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	int n, k, d, offset, temp, res, temp_d, size;
	cin >> n >> k >> d; //at least one edge of at least weight d
	if (n == k && k == d){
		cout << 1 << endl;
		return 0;
	}
	if (k > n) k = n;
	int* dp = new int[n];	
	dp[0] = 1;
	offset = res = 0;
	d--;
	//if there is only one child, amount of possible paths is (for n=1,2,3...): 1 1 2 4 7 11 16 ...
	//if there is two, amount of possible paths for the second branch is (for n=1,2,3...): 0 1 1 2 4 7 11 16 ...
	//if there is three, amount of possible paths for the third branch is (for n=1,2,3...): 0 0 1 1 2 4 7 11 ...
	//and so on, so we just need to sum all possible paths for each branch at n
	for(int i = 1; i < n; i++, offset++){ //building array with the values
		dp[i] = dp[i-1] + offset;
	}
		
	size = n;
	k = k - d;
	temp = n - 1;
	//cout << "k: " << k << ", size: " << size << endl;
	/*while(k > 0 && temp < size){*/
	while(k > 0 && temp >= 0){
		res += dp[temp--];
		k--;
	}
	cout << (res % 1000000007) << endl;
	return 0;
}

