#include "NodeInfo.h"
/*
 * This function prints contents of the linked list
 */
void printList(NodeInfo *node)
{
	NodeInfo* new_node = node; 
    
	string x = "";
    while(new_node != nullptr){
		if(new_node->checkIfDir() == false){
			x = "0";
		}else{
			x = "1";
		}
		
        cout << new_node->getNodeName() << " " << x << endl;
		new_node = new_node->next;
    }
}