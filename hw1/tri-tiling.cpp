#include <iostream>

//Tri tiling

using namespace std;

int f(int);
int g(int);

int f(int n){
	if (n <= 1) return 0;
	return f(n-2) + 2*g(n-1);
}

int g(int n){
	return 0;
}

int main(int argc, char *argv[]) {
	
	return 0;
}

