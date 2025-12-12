class Solution {
public:

    vector<int> dailyTemperatures(vector<int>& temperatures) 
    {
        // stack + vector to store results 
        vector<int> result(temperatures.size());
        stack<int> stck;

        // for each i (index) in temperatures
        for (int i = 0; i < temperatures.size(); ++i)
        {
            // while stack !empty and current temp[i] > top of stack temp
            while (!stck.empty() && temperatures[stck.top()] < temperatures[i])
            {
                // index = index at top of stack, pop index
                const auto indx = stck.top(); stck.pop();
                // result is i - index
                result[indx] = i - indx;
            }
            // push current index to stack
            stck.emplace(i);
        }
        // return result vector
        return result;
    }
};