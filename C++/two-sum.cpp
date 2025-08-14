#include <unordered_map>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // create unordered map taking storing ints and their count
        unordered_map<int, int> lookup;
        // for each num in vector 
        for (int i=0; i < nums.size(); ++i)
        {
            // if complement of current number exists
            if(lookup.count(target - nums[i]))
            {
                // return pair
                return {lookup[target - nums[i]], i};
            }
            // add current number to unordered map
            lookup[nums[i]] = i;
        }
        // no two numbers so return empty vector
        return {};
    }
};