#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

class ShortestPath{
public:
    vector<pair<int, int>> adj[101];


    // Complete the steps(1,2,3) in function networkDelayTime before you start with this
    void BFS(vector<int>& signalReceivedAt, int k) {

        // Initilize a queue for BFS traversal
        queue<int> q;

        // Push source node to the queue
        q.push(k);
        

        // SignalReceivedAt[k] should be set to 0
        signalReceivedAt[k] = 0;
        

        // Perform BFS
        while(!q.empty()){
            
            // Pop a node from the q. Assuming you name it as currNode
            int currNode = q.front(); 
            q.pop();

            // Iterate through adjList of this currNode
            for(pair<int, int> edge : adj[currNode]) {
                int time = edge.first;
                int neighborNode = edge.second;

                // Fastest signal for the neighborNode so far can  be either signalRecievedAt[neighborNode] or signalRecivedAt[currNode]+time
                if(signalReceivedAt[neighborNode] > signalReceivedAt[currNode]+time){
                    // Push the neighborNode to the q only if the signalRecivedAt[currNode]+time is lesser than signalRecievedAt[neighborNode]
                    q.push(neighborNode);

                    //Also set the signalReceived at neighborNode to this new time  = signalRecivedAt[currNode]+time
                    signalReceivedAt[neighborNode] = signalReceivedAt[currNode]+time;
                }
                //signalReceivedAt[neighborNode] = signalReceivedAt[currNode]+time;
            }
        }
    }
    
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // Note: It is not adjacency Matrix. It is adjacency List
        for (vector<int> time : times) {
            int source = time[0];
            int dest = time[1];
            int travelTime = time[2];
            
            adj[source].push_back({travelTime, dest});
        }

        // Step 2. Initialize a vector signalReceivedAt as a large value to signify that, so far, no signal has been received.
        vector<int> signalReceivedAt(n+1, INT_MAX); 
        signalReceivedAt.at(0) = 0;

        // Step 3. Call the BFS function. Go complete BFS function
        BFS(signalReceivedAt, k);
        
        // Step 4. Find maximum value in the signalReceivedAt vector and store it in variable named answer
        int max = 0;
        for(int i = 0; i < signalReceivedAt.size(); i++){
            if(signalReceivedAt.at(i) > max){
                max = signalReceivedAt.at(i);
            }
        }

        int answer = max;

        // INT_MAX signifies atleast one node is unreachable
        return answer == INT_MAX ? -1 : answer;
    }
};

int main(){
    vector<vector<int>> times{{ 2, 1, 1 }, 
                              { 2, 3, 5 }, 
                              { 2, 4, 1 }}; 
              
    int n = 4;
    int k = 1;
    
    ShortestPath obj;
    int answer = obj.networkDelayTime(times, n , k);
    cout << "Time taken for all nodes to receive signal " << answer << endl;;
    return 0;
    
}