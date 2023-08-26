#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
        //Store number:frequency in the map declared below
        map<int,int> mp;
        for(int i = 0; i < k; i++){
            mp[i] = 0;
        }

        // Result vector res-> top k frequent elements
        vector<int> res;

        //YOUR CODE : Implement Idea part(a) mentioned in the PDF
        
        for(int i = 0; i < nums.size(); i++){
            mp[nums[i]] += 1;
        }

        // Multimap to store the frequency:number 
        multimap<int,int,greater<int>> mmp;

        //YOUR CODE: Implement Idea part(b) mentioned in the PDF

        

        //YOUR CODE: Implement Idea part(c) mentioned in the PDF
       

        return res;
 }       

 int main(){

    vector<int> nums{1,2,3,1,1,2};
    int k=2;
    vector<int> res = topKFrequent(nums,k);

    for(int x:res){
        cout << x <<" ";
    }
    cout << endl;
    
    return 0;
 }