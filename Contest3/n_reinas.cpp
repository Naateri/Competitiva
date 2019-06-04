#include <iostream>
#include <vector>
#include <string>

typedef std::vector<int> int_vec;

int current_sum = 0;
int new_sum = 0;

int** create_matrix(int n){
	int** mat = new int*[n];
	mat[0] = new int[n*n];
	for (int i = 1; i < n; i++){
		mat[i] = mat[i-1] + n;
	}
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			mat[i][j] = 0;
		}
	}
	return mat;
}

void print_matrix(int** m, int n){ //works only for squared matrices
	for(int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			std::cout << m[i][j] << ' ';
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

bool safe_queen(int** mat, const int& pos_x, const int& pos_y){
	for(int i = 0; i < 8; i++){  //vertical
		if (i == pos_x) continue;
		if (mat[i][pos_y]) return false;
	}
	for(int i = 0; i < 8; i++){ //horizontal
		if (i == pos_y) continue;
		if (mat[pos_x][i]) return false;
	}
	for(int i = pos_x, j = pos_y; i >= 0 && j >= 0; i--, j--){ //upper-left
		if (mat[i][j]) return false;
	}
	for(int i = pos_x, j = pos_y; i < 8 && j < 8; i++, j++){ //lower-right
		if (mat[i][j]) return false;
	}
	for(int i = pos_x, j = pos_y; i >= 0 && j < 8; i--, j++){ //upper-right
		if (mat[i][j]) return false;
	}
	for(int i = pos_x, j = pos_y; i < 8 && j >= 0; i++, j--){ //lower-left
		if (mat[i][j]) return false;
	}
	return true;
}

bool n_queens_solver(int** mat, int queen){
	if (queen >= 8) return true; //all queens placed
	for (int i = 0; i < 8; i++){
		if (safe_queen(mat, i, queen)){
			//current_sum += mat[i][queen];
			//new_sum = mat[i][queen];
			mat[i][queen] = 1;
			if (n_queens_solver(mat, queen+1)) return true; //it found all queens
			mat[i][queen] = 0; //it failed
			//current_sum -= mat[i][queen];
		}
	}
	return false;
}

int get_sum(int** mat, int** mat2){
	int cur_sum = 0;
	for(int i = 0; i < 8; i++){
		for (int j = 0; j < 8; j++){
			if (mat2[i][j] == 1){
				cur_sum += mat[i][j];
			}
		}
	}
	return cur_sum;
}

void format(int res){
	std::string prnt;
	prnt = std::to_string(res);
	int tam = 5 - prnt.size();
	for(int i = 0; i < tam; i++)
		prnt = ' ' + prnt;
	std::cout << prnt << std::endl;
}

void n_queens(int** mat, int** mat2){
	int max_res = 0;
	for(int i = 0; i < 8; i++){
		if (n_queens_solver(mat, i)){
			int res = get_sum(mat2, mat);
			if (res > max_res) max_res = res;
			//std::cout << get_sum(mat2, mat) << std::endl;
		}// else std::cout << "No hay solucion.\n";
	}
	format(max_res);
}

int main(int argc, char *argv[]) {
	int k;
	int** mat;
	int** mat2;
	mat = new int*[8];
	for(int i = 0; i < 8; i++){
		mat[i] = new int[8];
	}
	std::cin >> k;
	for(int m = 0; m < k; m++){
		//input mat
		for(int i = 0; i < 8; i++){
			for(int j = 0; j < 8; j++){
				std::cin >> mat[i][j];
			}
		}
		mat2 = create_matrix(8);
		//print_matrix(mat, 8);
		n_queens(mat2, mat);
	}
	return 0;
}

