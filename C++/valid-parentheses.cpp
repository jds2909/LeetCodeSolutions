class Solution {
public:
    bool isValid(string s) 
    {
        // declare unordered map with closing bracket as key, opening bracket as value
        const unordered_map<char, char> symbol_pair = {{')', '('},
                                                       {']', '['},
                                                       {'}', '{'} };
        // declare stack
        stack<char> parentheses;

        // for each char in input string 'c'
        for (const auto& c : s)
        {
            // create iterator for current char 'c'
            const auto& it = symbol_pair.find(c);
            // if key 's' is found in unordered map
            if (it != symbol_pair.cend())
            {
                // early exit if stack is empty or top element of stack does not contain respective opening bracket
                if (parentheses.empty() || parentheses.top() != it->second)
                {
                    return false;
                }
                // otherwise if correct opening bracket is shown, pop from stack
                parentheses.pop();
            }
            // otherwise if char 'c' is not found as a key (opening bracket or just something else)
            else
            {
                // place char 'c' onto stack
                parentheses.emplace(c);
            }
        }
        // return true if empty stack (all opening had closes), return false if leftovers (something wasnt closed)
        return parentheses.empty();
    }
};