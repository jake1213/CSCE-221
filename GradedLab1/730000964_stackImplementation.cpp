#include <iostream>
#include <vector>
using namespace std;

class CustomStack {
public:
    vector<int> stack;
    int n;
    CustomStack(int maxSize) {
         n = maxSize;
    }
    
    void push(int x);
    int pop();
    void increment(int k, int val);
    void print();
};
    
void CustomStack::push(int x) {
    if(stack.size() < n){
        stack.push_back(x);
    }
}

int CustomStack::pop() {
    if(stack.size() != 0){
        int x = stack[stack.size()-1];
        stack.pop_back();
        return x;
    }
    return -1;
}

void CustomStack::increment(int k, int val){
    if(k < stack.size()){
        for(int i = 0; i < k; i++){
            stack[i] += val; 
        }
    }else{
        for(int j = 0; j < stack.size(); j++){
            stack[j] += val;
        }
    }
}
    
void CustomStack::print(){
    for(int i = stack.size()-1; i >= 0; i--){
        cout << stack[i] << endl;
    }
}

int main(){
    int maxSize = 10;
    CustomStack* obj = new CustomStack(maxSize);
    // Use obj->push(ele) to push into the stack
    // Use int x = obj->pop() to pop an element from the stack
    // Print the stack after push and pop operations
    // Use obj->increment(k,val) to increment last k elements of stack by value = val

    obj->push(10);
    int param_1 = obj->pop();
    cout << param_1 << endl;
    int param_2 = obj->pop();
    cout << param_2 << endl;
    obj->push(1);
    obj->push(2);
    obj->push(3);
    //int param_1 = obj->pop();
    //cout << param_1 << endl;
    obj->print();
    obj->increment(9,100);
    obj->print();
    
    return 0;
}


