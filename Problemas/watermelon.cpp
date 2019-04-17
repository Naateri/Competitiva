#include <iostream>
#include <string>

//watermelon problem from codeforces
//http://codeforces.com/problemset/problem/4/A

typedef std::string str;

int main(int argc, char *argv[]) {
	int w;
	str result;
	std::cin >> w;
	if (w > 2 && !(w%2)) result = "YES";
	else result = "NO";
	std::cout << result;
	return 0;
}

