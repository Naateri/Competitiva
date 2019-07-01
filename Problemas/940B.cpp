#include <iostream>
#include <vector>
using namespace std;

//int dp[2000000001] = {0};
vector<long long> dp;

int main(int argc, char *argv[]) {
	long long n, k, A, B;
	cin >> n >> k >> A >> B;
	dp.resize(n+1);
	for(long long i = n-1; i > 0; --i){
		if (i * k <= n)
			dp[i] = min(dp[i+1] + A, dp[i * k] + B);
		else dp[i] = dp[i+1] + A;
	}
	cout << dp[1] << endl;
	return 0;
}

