#include <iostream>
#include <vector>

using namespace std;

class CustomStack {
public:
    vector<int> stack, inc;
    int n;
    CustomStack(int maxSize) {
         n = maxSize;
    }
    
    void push(int x);
    int pop();
};
    
void CustomStack::push(int x){
    stack.push_back(x);
}
    
int CustomStack::pop() {
    int temp_size = 3;
    int temp_num = stack[temp_size-1];

    temp_size -= 1;
    return temp_num;
}

int main(){
    int maxSize = 10;
    CustomStack* obj = new CustomStack(maxSize);
    obj->push(10);
    obj->push(9);
    obj->push(8);

    int param_1 = obj->pop();
    int param_2 = obj->pop();
    int param_3 = obj->pop();

    //YOUR CODE HERE
    cout << param_1 << endl;
    cout << param_2 << endl;
    cout << param_3 << endl;
    
    return 1;
}


