#include <bits/stdc++.h>

using namespace std;

class MyQueue {
public:
    stack<int> input_st, output_st;
    int top_val = 0;
    MyQueue() {
        
    }
    
    void push(int x) {
        if (input_st.empty()){
            top_val = x;
        }
        input_st.push(x);
    }
    
    int pop() {
        if(output_st.empty()){
            int n = input_st.size();
            while(n){
                int temp = input_st.top();
                output_st.push(temp);
                input_st.pop();
                n--;
            }
        }
        int val = output_st.top();
        output_st.pop();
        return val;
    }
    
    int peek() {
        if(output_st.empty()){
            return top_val;
        }
        return output_st.top();
    }
    
    bool empty() {
        if(input_st.size() == 0 and output_st.size() == 0){
            return true;
        }
        return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */