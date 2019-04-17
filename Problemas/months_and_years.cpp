#include <iostream>
#include <list>
using namespace std;

list<int> months = {31,28,31,30,31,30,31,31,30,31,30,31};
list<int>::iterator first_value;
bool leap_year = 0;

list<int>::iterator still_looking(list<int>::iterator it, int* input, int n){
	//returns position to the list
	int temp = input[0];
	if (temp == 29) temp--;
	while(temp != (*it)){
		it++;
	}
	return it;
}

bool is_possible(list<int>::iterator it, int* input, int n){
	list<int>::iterator temp = it;
	temp++;
	leap_year = 0;
	for(int i = 0 ; i < n; i++){
		if (it == months.end()) it = months.begin(); //circular linked list simulation
		if (input[i] == 29){ //if there's 2 29's in the input
			if (leap_year) return 0;
			else leap_year = 1;
			input[i]--;
		}
		if (input[i] == (*it)){ //checking if the order is correct
			it++;
			continue;
		} else {
			it = still_looking(temp, input, n); //next value on list
			if (it == first_value) return 0; //until it hits the first value again
			return is_possible(it, input, n);
		}
	}
	return 1;
}


int main(int argc, char *argv[]) {
	int n, *input, i;
	list<int>::iterator it;
	cin >> n;
	input = new int[n];
	for (i = 0; i < n; i++){
		cin >> input[i];
		//if (input[i] == 29) leap_year = 1;
	}
	it = months.begin();
	it = still_looking(it, input, n);
	first_value = it; //first value could either be 28, 29, 30 or 31
	//leap_year = 0;
	if (is_possible(it,input,n)) cout << "Yes\n";
	else cout << "No\n";
	return 0;
}

