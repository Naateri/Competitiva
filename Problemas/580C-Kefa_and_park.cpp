#include <iostream>
#include <vector>
#include <list>
#include <stack>
using namespace std;

vector<int> cats;

struct Graph{
	vector<list<int>> nodes;
	vector<bool> visits;
	stack<int> my_stack;
	int max, leaves;
	Graph(int n, int m){
		nodes.resize(n);
		visits.resize(n);
		this->max = m;
		leaves = 0;
		list<int> temp;
		for(int i = 0; i < n; i++){
			nodes[i] = temp;
			visits[i] = 0;
		}
	}
	void add_edge(int x, int y){
		nodes[x-1].push_back(y-1);
		nodes[y-1].push_back(x-1);
	}
	void dfs(int s, int consecutive){
		if (cats[s]) consecutive++;
		else consecutive = 0;
		
		visits[s] = 1;
		if (consecutive > this->max) return;
		
		if (nodes[s].size() == 1 && s != 0){ //leaf
			leaves++;
		}
		for (list<int>::iterator it = nodes[s].begin(); it != nodes[s].end(); ++it){
			if ( !visits[*it] ){
				visits[*it] = 1;
				dfs(*it, consecutive);
			}
		}
	}		
};



int main(int argc, char *argv[]) {
	int n, m, x, y, root = 0;
	cin >> n >> m;
	Graph G(n,m);
	cats.resize(n);
	for(int i = 0; i < n; i++){
		cin >> cats[i];
	}
	for(int i = 0; i < n-1; i++){
		cin >> x >> y;
		G.add_edge(x,y);
	}
	G.dfs(0, 0);
	cout << G.leaves << endl;
	return 0;
}

