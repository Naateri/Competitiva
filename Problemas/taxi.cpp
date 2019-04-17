#include <iostream>
#include <list>
using namespace std;

void print_list(list<int> l){
	for(list<int>::iterator it = l.begin(); it != l.end(); it++){
		cout << (*it) << ' ';
	}
	cout << endl;
}

int main(int argc, char *argv[]) {
	
	list<int> groups;
	int* original_groups;
	int taxis = 0,n,s;
	bool in_node = 0;
	cin >> n;
	original_groups = new int[n];
	for(int i = 0; i < n; i++){
		cin >> s;
		original_groups[i] = s;
	}
	for(int i = 0; i < n; i++){
		in_node = 0;
		if (original_groups[i] == 4){
			taxis++;
			continue;
		}
		for(list<int>::iterator it = groups.begin(); it != groups.end(); it++){
			//cout << "(*it): " << *it << endl;
			//cout << "(*it) + original_groups["<<i<<"]: " << (*it) + original_groups[i] << endl;
			if ((*it) + original_groups[i] < 4){
				in_node = 1;
				(*it) += original_groups[i];
				break;
			} else if ((*it) + original_groups[i] == 4){
				//cout << "4\n";
				in_node = 1;
				groups.erase(it);
				taxis++;
				break;
			}
		}
		if (!in_node){
			//cout << "creating new node\n";
			groups.push_back(original_groups[i]);
		}
	}
	//cout << "groups in list: " << groups.size() << endl;
	//print_list(groups);
	cout << taxis + groups.size() << endl;
	return 0;
}

