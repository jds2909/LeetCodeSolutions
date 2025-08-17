class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> unprocessed_entries;
        for (const auto& num : nums)
        {
            unprocessed_entries.emplace(num);
        }

        int max_seq_count = 0;
        while (!unprocessed_entries.empty())
        {
            int num = *unprocessed_entries.begin();
            unprocessed_entries.erase(num);

            int lower_bound = num - 1;
            while (unprocessed_entries.count(lower_bound))
            {
                unprocessed_entries.erase(lower_bound);
                --lower_bound;
            }

            int upper_bound = num + 1;
            while (unprocessed_entries.count(upper_bound))
            {
                unprocessed_entries.erase(upper_bound);
                ++upper_bound;
            }
            max_seq_count = max(max_seq_count, upper_bound - lower_bound - 1);
        }
        return max_seq_count;
    }
};