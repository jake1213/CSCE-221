#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
        //Store number:frequency in the map declared below
        map<int,int> mp;

        // Result vector res-> top k frequent elements
        vector<int> res;

        //YOUR CODE : Implement Idea part(a) mentioned in the PDF
        for(auto i:nums)
            {
                mp[i]++;
            }

        // Multimap to store the frequency:number 
        multimap<int,int,greater<int>> mmp;

        //YOUR CODE: Implement Idea part(b) mentioned in the PDF
        for(auto i:mp)
        {
            mmp.insert({i.second,i.first});
        }
        

        //YOUR CODE: Implement Idea part(c) mentioned in the PDF
       
        int c=0;
        for(auto i:mmp)
        {
            res.push_back(i.second);
            c++;
            if(c==k)
            {
                break;
            }
        }
        return res;
 }       

 int main(){

    vector<int> nums{ 1,2,3,1,1,2 };
    int k=2;
    vector<int> res = topKFrequent(nums,k);

    for(int x:res){
        cout << x <<" ";
    }
    cout << endl;
    
    return 0;
 }