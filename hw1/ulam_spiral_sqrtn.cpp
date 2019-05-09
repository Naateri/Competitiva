#include <iostream>
#include <math.h>
using namespace std;

int power_of_two(int x){
	return x * x;
}

void ulam_spiral_sqrt(int num, int& x, int& y){
	/*
	odd powers of two: (x,-x) 
	1:x=0, 3(9):x=1, 5(25):x=2, 7(49):x=3 and so on
	it goes to the left and, if needed, up to find the coordinates
	even powers of two: (-x,x+1)
	2(4):x=0, 4(16):x=1, 6(36):x=2 and so on
	goes to the right and, if needed, down to find the coordinates
	both cases actually go through the spiral backwards
	Worst case scenario: sqrt(n) + 2 * sqrt(n) = O(sqrt(n))
	*/
	x = y = 0;
	int max_x, max_y, min_x, min_y, i, cur_x, cur_y, square_root, temp_i;
	char movement;
	i = 1;
	while ( (square_root = i*i) < num){ //sqrt(n)
		i++;
	}
	temp_i = i;
	i = i >> 1;
	if (temp_i&1) { //odd
		x = i;
		y = 0-x;
		if (num == square_root) return; //no need to do anything else
		max_x = x;
		max_y = -1*y;
		min_x = -1*x;
		min_y = y;
		movement = 'l';
	} else { //even
		y = i;
		x = 0 - (y-1);
		if (num == square_root) return; //no need to do anything elses
		min_x = x;
		max_x = -1*min_x + 1;
		max_y = y;
		min_y = -1*y - 1;
		movement = 'r';
	}
	cur_x = x; cur_y = y;
	bool b_x = 0, b_y = 0;
	bool nb_x = 0, nb_y = 0;
	/*
	movement explained on ulam_spiral_n.cpp
	*/
	i = square_root;
	while (i > num){ //loop can do maximum 2*sqrt(n) iterations
		if (movement == 'l'){
			while (min_x <= cur_x){
				cur_x--; i--;
				if (i == num){
					nb_x = 1;
					break;
				}
			}
			max_x++;
			movement = 'u';
		} else if (movement == 'u'){
			while (cur_y <= max_y){
				cur_y++; i--;
				if (i == num){
					b_y = 1;
					break;
				}
			}
			max_y++;
		} else if (movement == 'r'){
			while (cur_x <= max_x){
				cur_x++; i--;
				if (i == num){
					b_x = 1;
					break;
				}
			}
			min_x--;
			movement = 'd';
		} else {
			while (min_y <= cur_y){
				cur_y--; i--;
				if (i == num){
					nb_y = 1;
					break;
				}
			}
			min_y--;
		}
	}
	if (!b_x) cur_x++;
	else if (b_x) cur_x--;
	if (b_y) cur_y++;
	else if (!b_y) cur_y--;
	x = cur_x; y = cur_y;
}


int main(int argc, char *argv[]) {
	int n, x, y;
	cout << "Number in the spiral:\n";
	cin >> n;
	ulam_spiral_sqrt(n, x, y);
	cout << "x: " << x << ", y: " << y << endl;
	return 0;
}

