#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

typedef unordered_map<string, int> strmap;


int main(int argc, char *argv[]) {
	vector<string> answers;
	strmap hash;
	strmap::const_iterator got;	
	int n;
	string request;
	
	cin >> n;
	
	for(int i = 0; i < n; i++){
		cin >> request;
		got = hash.find(request);
		if (got == hash.end() ){ //new word
			hash[request] = 0;
			answers.push_back("OK");
		} else {
			hash[request]++;
			answers.push_back(got->first + to_string(got->second));
			//cout << got->first << got->second << endl;
		}
	}
	
	for (int i = 0; i < answers.size(); i++){
		cout << answers[i] << endl;
	}
	
	//stringmap::hasher fn = hash.hash_function();
	//cout << fn("lol");
	return 0;
}

