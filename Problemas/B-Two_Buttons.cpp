#include <iostream>
#include <queue>
using namespace std;

queue<int> my_queue;
bool visited[20001] = {0};
int dist[20001] = {};

int obj;

void bfs(){
	int cur_num;
	if (!my_queue.empty()){
		cur_num = my_queue.front();
		if (cur_num == obj){
			cout << dist[cur_num] << endl;
			return;
		}
		my_queue.pop();
		//visited[cur_num] = 1;
		if (cur_num << 1 <= 20000 && !visited[cur_num << 1]){ //red button
			my_queue.push(cur_num << 1);
			dist[cur_num << 1] = dist[cur_num] + 1;
			visited[cur_num << 1] = 1;
		}
		if (cur_num - 1 > 0 && !visited[cur_num - 1]) {//blue button
			my_queue.push(cur_num - 1);
			dist[cur_num - 1] = dist[cur_num] + 1;
			visited[cur_num - 1] = 1;
		}
		bfs();
	}
}

int main(int argc, char *argv[]) {
	int n;
	cin >> n >> obj;
	//bfs(n, m);
	my_queue.push(n);
	visited[n] = 1;
	bfs();
	return 0;
}

