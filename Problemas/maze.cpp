#include <iostream>
#include <string>
#include <queue>

using namespace std;

int** Graph, **bfs_graph;
int n, m, k, free_cells = 0;

struct position{
	int x, y;
};

queue<position> my_queue;

bool visit_neighbours(position pos){
	bool res = 0;
	position temp;
	/*for(temp.x = pos.x-1; temp.x <= pos.x + 1; temp.x++){
		if (temp.x < 0 || temp.x >= n) continue;
		for(temp.y = pos.y - 1; temp.y <= pos.y + 1; temp.y++){			
			if (temp.y < 0 || temp.y >= m) continue;
			if (Graph[temp.x][temp.y] == 1 && bfs_graph[temp.x][temp.y] == 0){			
				my_queue.push(temp);
				bfs_graph[temp.x][temp.y] = 1;
				res = 1;
			}
		}
	}*/
	temp.y = pos.y;
	if (pos.x > 0) {
		temp.x = pos.x-1;
		if (Graph[temp.x][temp.y] == 1 && bfs_graph[temp.x][temp.y] == 0){			
			my_queue.push(temp);
			bfs_graph[temp.x][temp.y] = 1;
			res = 1;
		}
	} 
	if (pos.x < n-1){
		temp.x = pos.x + 1;
		if (Graph[temp.x][temp.y] == 1 && bfs_graph[temp.x][temp.y] == 0){			
			my_queue.push(temp);
			bfs_graph[temp.x][temp.y] = 1;
			res = 1;
		}
	}
	temp.x = pos.x;
	if (pos.y > 0){
		temp.y = pos.y - 1;
		if (Graph[temp.x][temp.y] == 1 && bfs_graph[temp.x][temp.y] == 0){			
			my_queue.push(temp);
			bfs_graph[temp.x][temp.y] = 1;
			res = 1;
		}
	}
	if (pos.y < m-1){
		temp.y = pos.y + 1;
		if (Graph[temp.x][temp.y] == 1 && bfs_graph[temp.x][temp.y] == 0){			
			my_queue.push(temp);
			bfs_graph[temp.x][temp.y] = 1;
			res = 1;
		}
	}
	
	return res;
}

void real_bfs(int cur_node){
	bool flag;
	position v, temp;
	//if (cur_node == (free_cells-k)) return;	
	if (! my_queue.empty() ){
		flag = 0;
		v = my_queue.front();
		my_queue.pop();
		bfs_graph[v.x][v.y] = 2; //black
		cur_node++;
		Graph[v.x][v.y] = 2;
		visit_neighbours(v);		
		if (cur_node == (free_cells-k)) return;	
		//if (cur_node == k) return;
		real_bfs(cur_node);
	}
}


void bfs(position pos){
	int cur_node = 0;
	my_queue.push(pos);
	bfs_graph[pos.x][pos.y] = 1; //gray
	real_bfs(cur_node);
}


int main(int argc, char *argv[]) {
	bool flag = 0;
	position pos;
	string line;
	cin >> n >> m >> k;
	Graph = new int*[n];
	bfs_graph = new int*[n]();
	for(int i = 0; i < n; i++){
		Graph[i] = new int[m];
		bfs_graph[i] = new int[m]();
		cin >> line;
		for(int j = 0; j < line.size(); j++){
			if (line[j] == '#') Graph[i][j] = 0;
			else{				
				Graph[i][j] = 1;
				free_cells++;
				if (!flag){ //so we know where to start dfs
					pos.x = i; pos.y = j; 
					flag = 1;
				}
			}		
		}
	}	
	bfs(pos);
	for(int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			if (Graph[i][j] == 0) cout << "#";
			else if (Graph[i][j] == 1) cout << "X";
			else cout << ".";
		}
		cout << endl;
	}
	return 0;
}

