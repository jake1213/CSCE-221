#ifndef _NODEINFO_H
#define _NODEINFO_H

#include <string>
#include <vector>
#include <cctype>
#include <fstream>
#include <sstream>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

class NodeInfo
{
    private:
        bool is_dir;
        string name;
        string p_name;

    public:
        NodeInfo *parent = nullptr;
        NodeInfo *next = nullptr;
        vector<NodeInfo> children;
        void setIfDir(string);
        void setName(string);
        void setParentName(string);
        void setParent(string);
        bool checkIfDir();
        //~NodeInfo();
        NodeInfo(bool is_dir, string name, string p_name);
        string getNodeName();
        string getParentName();
        NodeInfo* getParent();
        vector<NodeInfo> getChildren();
};

/*
NodeInfo::~NodeInfo(){
    NodeInfo* new_node1 = parent; 
    NodeInfo* new_node2 = parent;

    new_node1 = new_node1->next;
    while(new_node1 != nullptr){
        new_node1 = new_node1->next;
        new_node2 = new_node2->next;

        delete new_node2;
    }
}
*/

NodeInfo::NodeInfo(bool is_dir, string name, string p_name){
    this->is_dir = is_dir;
    this->name = name;
    this->p_name = p_name;
}

/*
string
NodeInfo::getParentName()
{
    p_name = p_name.substr(0,p_name.length()-1);
    return p_name;
}
void
NodeInfo::setParentName(string par_name)
{
    p_name = par_name;
}
void

NodeInfo::setParent(string par_name)
{
    // Not needed in assignment 1
}
*/

void
NodeInfo::setIfDir(string dir_str)
{
	
	if(dir_str == "file"){
        this->is_dir = false;
    }else if(dir_str == "dir"){
        this->is_dir = true;
    }
}

void
NodeInfo::setName(string name_str)
{
	this->name = name_str;
}

bool
NodeInfo::checkIfDir()
{
	return is_dir;
}

string
NodeInfo::getNodeName()
{
    return name;
}

/*
NodeInfo*
NodeInfo::getParent()
{
	//Not needed in assignment 1
    return NULL;
}
vector<NodeInfo>
NodeInfo::getChildren()
{
    //Not needed in assignment 1 
}
*/

void printList(NodeInfo *);
void append(NodeInfo**, vector<string>);
vector<string> tokenize_input_string(string);

#endif