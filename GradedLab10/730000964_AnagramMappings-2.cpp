#include <iostream>
#include <vector>
#include <map>

using namespace std;


class Solution {
public:

vector<int> anagramMappings(vector<int>& nums1, vector<int>& nums2) {
    vector<int> ans = nums1; // ans is the index mapping array that you should return(Refer to PDF for definition)
    
    //Declare a map<x,y> where x and y are data types based on your solution. 
    map<int, int> map1;
    
    for(int i = 0; i < nums1.size(); i++){
        for(int j = 0; j < nums2.size(); j++){
            if(nums1.at(i) == nums2.at(j)){
                map1.emplace(nums1.at(i), j);
            }
        }
    }

    for(int i = 0; i < ans.size(); i++){
        ans.at(i) = map1.at(ans.at(i));
    }

    return ans;
}
};

int main(){
    vector<int> nums1 = {12,28,46,32,50};
    vector<int> nums2 = {12,28,46,32,50};
    vector<int> ans1;
    Solution obj;

    //Call the function anagramMappings and print out the output vector(index mapping array)
    ans1 = obj.anagramMappings(nums1, nums2);

    for(int i = 0; i < ans1.size(); i++){
        cout << ans1.at(i) << " ";
    }
    cout << endl;

    return 0;
}