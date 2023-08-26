#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

int countWords(string list[], int n, int k){
	int count = 0;
	map<string,int> m;
	m["The"] = 0;
	m["first"] = 0;
	m["second"] = 0;
	m["was"] = 0;
	m["alright"] = 0;
	m["but"] = 0;
	m["the"] = 0;
	m["not"] = 0;

	for(int i = 0; i < n; i++){
		m[list[i]] += 1;

		if(m[list[i]] == k){
			count += 1;
		}else if(m[list[i]] > k){
			count -= 1;
		}
	}
	
	return count;
}

int main(){

	string words[11] = {"The", "first", "second", "was", "alright", "but", "the",  "second", "second", "was", "not"};
	int k = 2;
	int size = sizeof(words)/sizeof(words[0]);
	int result = countWords(words,size,k);
	cout << "Number of words appearing exactly " << k << " times = " << result << endl; 
	return 0;
}