class MinStack {
public:

    // push all values to mystack
    // if value is less than current minstack top value, push to minstack also

    // restraints:
    // duplicate values are stored

    // constructor
    MinStack() {
    }

    // stack for all nums, stack for min nums
    stack<int> mystack;
    stack<int> minstack;

    void push(int val) {
        // if minstack is empty or val is less than current top, push val to both stacks
        if (minstack.empty() || val <= minstack.top())
        {
            minstack.push(val);
            mystack.push(val);
        }

        // otherwise push value solely to mystack
        else
        {
            mystack.push(val);
        }
    }

    void pop() {
        // if the top value is the same on both stacks, pop from both stacks
        if (mystack.top() == minstack.top())
        {
            mystack.pop();
            minstack.pop();
        }
        // otherwise pop solely from mystack
        else
        {
            mystack.pop();
        }
    }

    // return top val of regular stack
    int top() {
        return mystack.top();
    }

    // return top value of minstack (current min value) 
    int getMin() {
        return minstack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */