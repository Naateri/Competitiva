#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> cur_solutions;
int* songs;
int cur_max;
bool ans;


int sol_sum(vector<int> solutions){
	int sum = 0;
	for(int i = 0; i < solutions.size(); i++){
		sum += solutions[i];
	}
	return sum;
}

void print_solution(){
	for(int i = 0; i < cur_solutions.size(); i++){
		cout << cur_solutions[i] << ' ';
	}
	cout << "sum:" << cur_max << endl;
}

void erase_0(){
	for(int i = 0; i < cur_solutions.size(); i++){
		if (cur_solutions[i] == 0){
			cur_solutions.erase(cur_solutions.begin() + i);
			i--;
		}
	}
}

void solution(int pos, int n, int N, vector<int> solutions){
	if (pos > n){
		if (sol_sum(solutions) > cur_max){
			cur_max = sol_sum(solutions);
			cur_solutions.clear();
			cur_solutions = solutions;
		}
		return;
	}
	solutions.push_back(songs[pos]);
	int cur_sum = sol_sum(solutions);
	if (cur_sum > N){
		solutions.erase(solutions.end() - 1); //erasing last inserted element
		solution(pos+1, n, N, solutions);
		print_solution();
	}
	else if (cur_sum == N){
		ans = 1;
		cur_max = sol_sum(solutions);
		cur_solutions.clear();
		cur_solutions = solutions;
		return;
	}
	for(int i = pos+1; i < n; i++){
		solution(i, n, N, solutions);
	}
//	solution(pos+1, n, N);
}

void real_solutions(int n, int N){
	for(int i = 0; i < n; i++){
		vector<int> s;
		solution(i, n, N, s);
		if (ans){
			ans = 0;
			break;
		}
	}
}


int main(int argc, char *argv[]) {
	while(1){
		cur_solutions.clear();
		ans = 0;
		int N, n;
		cin >> N >> n;
		songs = new int[n];
		for(int i = 0; i < n; i++){
			cin >> songs[i];
		}
		cur_max = -1;
		//solution(0, n, N);
		real_solutions(n, N);
		erase_0();
		print_solution();
		
		delete[] songs;
	}
	
	return 0;
}

