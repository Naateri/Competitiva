#include <iostream>
#include <string>
#include <list>
using namespace std;

typedef string str;

str res1 = "CHAT WITH HER!\n";
str res2 = "IGNORE HIM!\n";

void find_letter(list<char>& l, char let){
	for(list<char>::iterator it = l.begin(); it != l.end(); it++){
		if ((*it) == let){
			return;
		}
	}
	l.push_back(let);
}

int main(int argc, char *argv[]) {
	str inp;
	cin >> inp;
	list<char> letters;
	for(int i = 0; i < inp.size(); i++){
		find_letter(letters, inp[i]);
	}
	int s = letters.size();
	if (s & 1) cout << res2;
	else cout << res1;
	return 0;
}

