#include <unordered_set>

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        //create unordered set (takes unique elements only) and pass all vector values
        unordered_set<int> nums_set(nums.begin(), nums.end());
        // if unordered_set does not equal num size then true for duplicates,
        // false otherwise      
        return nums_set.size() != nums.size();
    }
};