#include <iostream>
using namespace std;

void ulam_spiral(int num, int& x, int& y){
	x = y = 0;
	int max_x, max_y, min_x, min_y, i, cur_x, cur_y;
	char movement = 'r';
	/*
	movement: 'r' -> right, x adds up. We only care about max_x.
	'u' -> up, y adds up. We only care about max_y.
	'l' -> left, x is reduced. We only care about min_x.
	'd' -> down, y is reduced. We only care about min_y.
	*/
	max_x = 0; max_y = 0; i = 1; min_x = 0; min_y = 0;
	i = 1;
	while (i < num){ //loop goes through all numbers exactly, thus being O(n)
		if (movement == 'r'){
			while (cur_x <= max_x){
				cur_x++; i++;
				if (i == num) break;
			}
			max_x++;
			movement = 'u';
		} else if (movement == 'u'){
			while (cur_y <= max_y){
				cur_y++; i++;
				if (i == num) break;
			}
			max_y++;
			movement = 'l';
		} else if (movement == 'l'){
			while (min_x <= cur_x){
				cur_x--; i++;
				if (i == num) break;
			}
			min_x--;
			movement = 'd';
		} else {
			while (min_y <= cur_y){
				cur_y--; i++;
				if (i == num) break;
			}
			min_y--;
			movement = 'r';
		}
	}
	x = cur_x; y = cur_y;
}

void inverse_ulam(int num, int x, int y){
	x = y = 0;
	int max_x, max_y, min_x, min_y, i, cur_x, cur_y;
	char movement = 'r';
	/*
	movement: 'r' -> right, x adds up. We only care about max_x.
	'u' -> up, y adds up. We only care about max_y.
	'l' -> left, x is reduced. We only care about min_x.
	'd' -> down, y is reduced. We only care about min_y.
	*/
	max_x = 0; max_y = 0; i = 1; min_x = 0; min_y = 0;
	i = 1;
	while (cur_x != x && cur_y != y){ //loop goes through all numbers exactly, thus being O(n)
		if (movement == 'r'){
			while (cur_x <= max_x){
				cur_x++; i++;
				if (i == num) break;
			}
			max_x++;
			movement = 'u';
		} else if (movement == 'u'){
			while (cur_y <= max_y){
				cur_y++; i++;
				if (i == num) break;
			}
			max_y++;
			movement = 'l';
		} else if (movement == 'l'){
			while (min_x <= cur_x){
				cur_x--; i++;
				if (i == num) break;
			}
			min_x--;
			movement = 'd';
		} else {
			while (min_y <= cur_y){
				cur_y--; i++;
				if (i == num) break;
			}
			min_y--;
			movement = 'r';
		}
	}
	num = i;
}

int main(int argc, char *argv[]) {
	int n, x, y;
	cout << "Number in the spiral:\n";
	cin >> n;
	ulam_spiral(n, x, y);
	cout << "x: " << x << ", y: " << y << endl;
	cout << "Coordinates: "; cin >> x >> y;
	inverse_ulam(n, x, y);
	cout << "number: " << n << endl;
	return 0;
}

