/*
1. List of students: Cory Overgaard
2. External Sources: 
3. Concerns: None
*/
#include <map>
#include <string>
#include <vector>
#include <iostream>
#include "../Include/heapsort.h"


using namespace std;

enum city_names{
   HOU, SEAT, SFO, LA, SLC, PHNX, DENV, DAL, MINN, CHGO, KC, EWR, BOS
};

int shortestPath(vector<vector<int>> &list, int source, int destination){
    //Initialize an adjacency vector
    vector<vector<pair<int,int>>> adj(list.size());

    //Initialize the heap
    Heap heap;

    //push into the adjaceny vector for every element in flight
    for(vector<int>  time : list) {
        int src = time[0];
        int dest = time[1];
        int cost = time[2];
        
        //Push into the 
        adj[src].push_back({dest, cost});
    }

    //insert the initial cost
    heap.insert(0, source);

    while(!heap.isEmpty()){
        //Set the cost to the first element in the heap
        int cost = heap.min().at(0);
        int node = heap.min().at(1);

        //Pop from heap
        heap.removeMin();

        //Return cost if you have reached the destination
        if(node == destination){
            return cost;
        }
        
        //Find shortest path and appened the cost to the heap
        for(unsigned i = 0; i < adj[node].size(); i++){
            heap.insert(adj[node].at(i).second + cost, adj[node].at(i).first);  
        }
    }

    return -1;
}

int main(int argc, char** argv){
    //Temp variable to hold argv
    string temp = argv[1];

    //Determine if flight, road, or error.
    if(temp == "road"){
        //Format: {Start, Dest, Dist}
        vector<vector<int>> roads = {{HOU, DAL, 239}, {HOU, EWR, 1618}, {EWR, BOS, 225}, {EWR, KC, 1183}, {BOS, CHGO, 983}, {CHGO, KC, 510}, {KC, DAL, 556}, {DAL, DENV, 794}, {HOU, PHNX, 1176}, {PHNX, LA, 372}, {LA, SFO, 383}, {LA, SLC, 688}, {PHNX, DENV, 865}, {DENV, SLC, 371}, {SLC, SEAT, 839}, {SFO, SEAT, 808}, {SEAT, MINN, 1655}, {MINN, CHGO, 409}, {SLC, MINN, 1245}, {DENV, MINN, 680}, {DAL, HOU, 239}, {EWR, HOU, 1618}, {BOS, EWR, 225}, {KC, EWR, 1183}, {CHGO, BOS, 983}, {KC, CHGO, 510}, {DAL, KC, 556}, {DENV, DAL, 794}, {PHNX, HOU, 1176}, {LA, PHNX, 372}, {SFO, LA, 383}, {SLC, LA, 688}, {DENV, PHNX, 865}, {SLC, DENV, 371}, {SEAT, SLC, 839}, {SEAT, SFO, 808}, {MINN, SEAT, 1655}, {CHGO, MINN, 409}, {MINN, SLC, 1245}, {MINN, DENV, 680}};

        //City vector
        vector<vector<string>> road_cities = {{"Seattle", "SEAT"}, {"San Fransisco", "SFO"}, {"Los Angeles", "LA"}, {"Salt Lake City", "SLC"}, {"Phoenix", "PHNX"}, {"Denver", "DENV"}, {"Dallas", "DAL"}, {"Minneapolis", "MINN"}, {"Chicago", "CHGO"}, {"Kansas City", "KC"}, {"Newark", "EWR"}, {"Boston", "BOS"}};
        
        //Print for distance for each city from Houston
        cout << "The minimum distance from Houston to" << endl;
        cout << "Seattle" << " is " << shortestPath(roads, HOU, SEAT) << endl;
        cout << "San Fransisco" << " is " << shortestPath(roads, HOU, SFO) << endl;
        cout << "Los Angeles" << " is " << shortestPath(roads, HOU, LA) << endl;
        cout << "Salt Lake City" << " is " << shortestPath(roads, HOU, SLC) << endl;
        cout << "Phoenix" << " is " << shortestPath(roads, HOU, PHNX) << endl;
        cout << "Denver" << " is " << shortestPath(roads, HOU, DENV) << endl;
        cout << "Dallas" << " is " << shortestPath(roads, HOU, DAL) << endl;
        cout << "Minneapolis" << " is " << shortestPath(roads, HOU, MINN) << endl;
        cout << "Chicago" << " is " << shortestPath(roads, HOU, CHGO) << endl;
        cout << "Kansas City" << " is " << shortestPath(roads, HOU, KC) << endl;
        cout << "Newark" << " is " << shortestPath(roads, HOU, EWR) << endl;
        cout << "Boston" << " is " << shortestPath(roads, HOU, BOS) << endl;
    }else if(temp == "flight"){
        //Format: {Start, Dest, Dist}
        vector<vector<int>> flights = {{HOU, EWR, 1400}, {EWR, BOS, 201}, {BOS, CHGO, 867}, {CHGO, KC, 403}, {CHGO, MINN, 334}, {KC, DAL, 461}, {DAL, DENV, 641}, {MINN, DENV, 680}, {MINN, SLC, 991}, {SLC, SEAT, 689}, {SEAT, SFO, 679}, {SFO, LA, 337}, {LA, SLC, 590}, {LA, PHNX,370 }, {PHNX, DENV, 853}, {PHNX, HOU, 1009}, {DENV, CHGO, 1002}, {EWR, HOU, 1400}, {BOS, EWR, 201}, {CHGO, BOS, 867}, {KC, CHGO, 403}, {MINN, CHGO, 334}, {DAL, KC, 461}, {DENV, DAL, 641}, {DENV, MINN, 680}, {SLC, MINN, 991}, {SEAT, SLC, 689}, {SFO, SEAT, 679}, {LA, SFO, 337}, {SLC, LA, 590}, {PHNX, LA, 370 }, {DENV, PHNX, 853}, {HOU, PHNX, 1009}, {CHGO, DENV, 1002}};

        //City vector
        vector<vector<string>> flight_cities = {{"Seattle", "SEAT"}, {"San Fransisco", "SFO"}, {"Los Angeles", "LA"}, {"Salt Lake City", "SLC"}, {"Phoenix", "PHNX"}, {"Denver", "DENV"}, {"Dallas", "DAL"}, {"Minneapolis", "MINN"}, {"Chicago", "CHGO"}, {"Kansas City", "KC"}, {"Newark", "EWR"}, {"Boston", "BOS"}};

        //Print for distance for each city from Houston
        cout << "The minimum distance from Houston to" << endl;
        cout << "Seattle" << " is " << shortestPath(flights, HOU, SEAT) << endl;
        cout << "San Fransisco" << " is " << shortestPath(flights, HOU, SFO) << endl;
        cout << "Los Angeles" << " is " << shortestPath(flights, HOU, LA) << endl;
        cout << "Salt Lake City" << " is " << shortestPath(flights, HOU, SLC) << endl;
        cout << "Phoenix" << " is " << shortestPath(flights, HOU, PHNX) << endl;
        cout << "Denver" << " is " << shortestPath(flights, HOU, DENV) << endl;
        cout << "Dallas" << " is " << shortestPath(flights, HOU, DAL) << endl;
        cout << "Minneapolis" << " is " << shortestPath(flights, HOU, MINN) << endl;
        cout << "Chicago" << " is " << shortestPath(flights, HOU, CHGO) << endl;
        cout << "Kansas City" << " is " << shortestPath(flights, HOU, KC) << endl;
        cout << "Newark" << " is " << shortestPath(flights, HOU, EWR) << endl;
        cout << "Boston" << " is " << shortestPath(flights, HOU, BOS) << endl;
    }else{
        cout << "Invalid Input: Please enter 'road' or 'flight'" << endl;
    }
}