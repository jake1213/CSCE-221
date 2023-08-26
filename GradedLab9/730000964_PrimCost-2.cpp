#include <iostream>
#include <vector>
#include <queue>

using namespace std;


class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size(); 
        
        // Min-heap to store minimum weight edge at top.
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
        
        // Track nodes which are included in MST.
        vector<bool> inMST(n);
        int mstCost = 0;
        int edgesUsed = 0;

        // Push the node 0 and it's weight(manhattan distance from currNode) to the heap (Step 2). IMPORTANT: We push the index of the point. (1 POINT) 
        heap.push({0,0});
        
        
        while (edgesUsed < points.size()) // (1 POINT)
        {    
            // Get minimum weighted edge and node from top of the heap  and pop it(Step 2(a)). Let's call is currNode and weight (2 POINTS)
            //YOUR CODE HERE
            pair<int, int> node = heap.top();
            int currNode = node.first;
            int weight = node.second;
            heap.pop();
            
            // If node was already included in MST we will discard this edge.  (1 POINT)
            //YOUR CODE HERE
            if(inMST.at(currNode)){
                continue;
            }

            //Mark currNode as visited using inMST vector<bool> (1 POINT)
            //Increment the mstCost and edges used (The weight popped will be added to the existing mstCost)  (1 POINT)
            inMST[currNode] = true;
            mstCost += weight;
            edgesUsed++;
            
            //Iterate through the other nodes. Since we are storing the nodes as the inddex of the points in the array, it would be a simple for loop to iterate (3 POINTS)
            for (int nextNode = 0; nextNode < n; ++nextNode) {

                // If next node is not in MST, then push the edge from curr node in the priority queue.Push (nextNode, newWeight)
                // This new weight is the manhattan distance between the currNode and the nextNode (Definition given in the question - PDF)
                //YOUR CODE HERE
                if(!inMST.at(nextNode)){
                    heap.push({nextNode, (abs(points.at(currNode).at(0) - points.at(nextNode).at(0)) + abs(points.at(currNode).at(1)-points.at(nextNode).at(1)))});
                }
            }
        }
        
        return mstCost;
    }
};

int main() {
    vector<vector<int>> points = {{0, 0}, {3, 0}, {3, 10}, {5, 2}, {5, 0}};
    //vector<vector<int>> points ={{3,12},{-2,5},{-4,1}};
    Solution solution;
    cout << "Minimum Cost to Connect Points = " << solution.minCostConnectPoints(points) << endl;
    return 0;
}