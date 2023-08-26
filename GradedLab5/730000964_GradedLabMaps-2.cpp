#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<string> findRepeatedDnaSequences(string s) {

        vector<string> res;
        unordered_map<string,int> map;
        
        for(int i = 0; i < s.length(); i++){
            map[s.substr(i, 10)] += 1;
        }

        for(auto i : map){
            if(i.second > 1){
                res.push_back(i.first);      
            }
        }

        return res;
    }

int main()
{   
    string s = "";
    vector<string> output = findRepeatedDnaSequences(s);

    //YOUR CODE HERE : Print the output vector
    for(int i = 0; i < output.size(); i++){
        cout << output[i] << " ";
    }

    cout << endl;
    
    return 0;
}
