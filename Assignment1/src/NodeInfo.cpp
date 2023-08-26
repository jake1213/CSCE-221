/*
1. List of students: Cory Overgaard, Yezen Hijazin, Ryan Paul
2. External Sources: tutorialspoint.com, geeksforgeeks.org, Peer Teachers in PETR 127
3. Concerns: None
*/
#include <string>
#include <vector>
#include <cctype>
#include <fstream>
#include <sstream>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <bits/stdc++.h>
#include "NodeInfo.h"
#include "PrintList.cpp"

#define DEBUG 0


using namespace std;
vector<string>
tokenize_input_string(string line)
{
    char space_char = ' ';
    vector<string> words{};

    stringstream sstream(line);
    string word;
    while (std::getline(sstream, word, space_char))
    {
        word.erase(std::remove_if(word.begin(), word.end(), ::ispunct), word.end());
        words.push_back(word);
        if (DEBUG) cout << "Word:" << word << endl;
    }
    if (DEBUG) cout << " " << endl;
    return words;
}

void
append(NodeInfo** head_ref, vector<string> new_data)
{
    bool x = false;
    if(new_data[0] == "dir"){
        x = true;
    }

    NodeInfo* new_node = new NodeInfo(x, new_data[1], new_data[2]);
    new_node->next = NULL;

    if(*head_ref == NULL){
        *head_ref = new_node;
    }else{
        NodeInfo* cur = *head_ref;

        while(cur->next != NULL){
            cur = cur->next;
        }

        new_node->next = NULL;
        cur->next = new_node;
        //delete cur;
    }
} 

#define MAXLNSZ 256

int main(int argc, char **argv)
{
    string line;
    char *filename = (char *) malloc(MAXLNSZ * sizeof(char));
    NodeInfo *tree_node = NULL;
    vector<string> lines{};
    vector<string> words;
    strcpy(filename, argv[1]);
    string files(filename);

    ifstream input_file(files);
    if (!input_file.is_open())
    {
        cerr << "Could not open the file - '"
             << files << "'" << endl;
        return EXIT_FAILURE;
    }
    
    while (getline(input_file, line))
    {
        lines.push_back(line);
        words = tokenize_input_string(line);
        append(&tree_node, words);
    }
    printList(tree_node);
    input_file.close();
    delete tree_node;
    free(filename);
    filename = NULL;
    if (DEBUG) cout << "Check Program Exiting " << endl;
    return EXIT_SUCCESS;
}