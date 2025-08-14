#include <unordered_map>

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        // hash map takes number and frequency
        unordered_map<int, int> numcounts;
        // for each num in nums add to hashmap or increase count
        for (const auto& i : nums)
        {
            ++numcounts[i];
        }
        // buckets vector taking frequency as identifier and inserting numbers that 
        // appear that many times
        vector<vector<int>> buckets(nums.size() +1);
        for (const auto& kvp : numcounts)
        {
            buckets[kvp.second].emplace_back(kvp.first);
        }

        // vector to contain top k elements loops backwards from highest index bucket
        // highest index contains num(s) that appeared most
        vector<int> results;
        for (int i = buckets.size() - 1; i >= 0; --i)
        {
            for (int j = 0; j < buckets[i].size(); ++j)
            {
                results.emplace_back(buckets[i][j]);
                // when results has k elements stop loop return results
                if (results.size() == k)
                {
                    return results;
                }
            }
        }
        // return if early exit not triggered (e.g. top 5 elements in a nums vector 
        // with 3 numbers)
        return results;
    }
};