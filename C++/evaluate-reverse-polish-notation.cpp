class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        // define stack
        stack<int> mystack;

        // for each string t in tokens
        for (const auto& t : tokens)
        {
            // if t is an operator
            if (isOp(t))
            {
                // take b from top & pop
                int b = mystack.top(); mystack.pop();
                // take a from top & pop
                int a = mystack.top(); mystack.pop();
                // use apply method to calculate and push back to stack
                mystack.push(apply(a, b, t[0]));
            }
            else
            {
                // if not an operator, push num to stack
                mystack.push(stoi(t));
            }
        }
        // answer is left on stack so return
        return mystack.top();
    }

private:

    // helper function checks if operator char or more than one char like -2
    static bool isOp(const string& s)
    {
        return s.size() == 1 && (s[0] == '+' || s[0] == '-' || s[0] == '/' || s[0] == '*');
    }

    // calc helper just returns calculation from input
    static int apply(int a, int b, char op)
    {
        switch (op)
        {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        }

        return 0;
    }
};