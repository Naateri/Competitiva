#include <iostream>

//Tri tiling

/*two recurrence relations: 
f(n) = f(n-2) + 2*g(n-1) -> full canvas (original problem)
a(n) = f(n-1) + a(n-2) -> canvas without lower left corner
f(n) only has a solution for even n's
a(n) only has a solution for odd n's
we only care for f(n) -> that's the answer

we know that: f(2) = 3
f(2) = f(0) + 2*a(1)
a(1) = 1 (1x3 without lower left corner = 1x2)
then:
f(2) = f(0) + 2 * a(1) = f(0) + 2 = 3 -> f(0) = 1

We also know that:
f(1) = 0 and a(2) = 0
so:
a(2) = f(1) + a(0)
a(2) = 0 + a(0) = 0 -> a(0) = 0
we're ready to solve the recurrence for whichever n we want
*/

using namespace std;

int *f, *a;

//f[n] = f(n)

void tri_tiling(int n){
	f[0] = a[1] = 1;
	a[0] = f[1] = 0;
	for(int i = 2; i <= n; i++){
		f[i] = f[i-2] + (a[i-1] << 1);
		a[i] = f[i-1] + a[i-2];
	}
}

int main(int argc, char *argv[]) {
	int n, res;
	cout << "Input: length (n): ";
	cin >> n;
	f = new int[n+1]; a = new int[n+1];
	tri_tiling(n);
	res = f[n];
	cout << "Ways: " << res << endl;
	delete[] f;
	delete[] a;
	return 0;
}

