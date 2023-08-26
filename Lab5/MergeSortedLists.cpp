/*Question: Create two linked lists l1 and l2 such that l1 and l2 are sorted.
            Use the concept of recursion to merge these two sorted lists into a single list 
  Example : l1 = [1,3,4] l2 = [2,5,6] Expected output: [1,2,3,4,5,6]     
            l1 = []      l2 = [4,7,8] Expected output: [4,7,8]                 
*/

 #include <iostream>
 using namespace std;
 struct ListNode {
     int data;
     ListNode *next;
  };

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    if(l1->next == NULL){
        return l2;
    }else if(l2->next == NULL){
        return l1;
    }else{
        if(l1->data >= l2->data){
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }

        if(l1->data < l2->data){
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
    }
}

void printList(ListNode* node){
    while(node->next != NULL){
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

int main(){
    ListNode* newNode;
    ListNode* result;
    
    ListNode* head1 = new ListNode();
    ListNode* head2 = new ListNode();

    head1->data = 0;
    head2->data = 1;

    //l1 Initialize
    ListNode* l1_1 = new ListNode();
    l1_1->data = 1;
    head1->next = l1_1;

    ListNode* l1_2 = new ListNode();
    l1_2->data = 2;
    l1_1->next = l1_2;

    ListNode* l1_3 = new ListNode();
    l1_3->data = 3;
    l1_2->next = l1_3;

    ListNode* l1_4 = new ListNode();
    l1_4->data = 4;
    l1_3->next = l1_4;
    l1_4->next = NULL;

    //l2 Initialize
    ListNode* l2_2 = new ListNode();
    l2_2->data = 2;
    head2->next = l2_2;

    ListNode* l2_3 = new ListNode();
    l2_3->data = 3;
    l2_2->next = l2_3;

    ListNode* l2_4 = new ListNode();
    l2_4->data = 4;
    l2_3->next = l2_4;

    ListNode* l2_5 = new ListNode();
    l2_5->data = 5;
    l2_4->next = l2_5;
    l2_5->next = NULL;

    
    cout << "Before merging"<<endl;
    printList(head1);
    printList(head2);


    result = mergeTwoLists(head1,head2);

    cout << "After merging"<<endl;
    printList(result);
}