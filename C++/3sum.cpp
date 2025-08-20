class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        sort(nums.begin(), nums.end());
        vector<vector<int>> res;

        // iterate backwards from right most num, until third from left
        for (int i = size(nums) - 1; i >= 2; --i)
        {
            // if there is a duplicate num on left skip current num
            if (i + 1 < nums.size() && nums[i] == nums[i + 1])
            {
                continue;
            }
            // target is negative of current index (e.g. current num 2 is -2 to get to 0)
            const auto& target = -nums[i];
            // declar left and right pointers
            int left = 0, right = i - 1;
            while (left < right)
            {
                // if pointers sum less than target increase left pointer to make larger 
                // sum (sorted array)
                if (nums[left] + nums[right] < target)
                {
                    ++left;
                }
                // if pointers sum larger than target decrease right pointer to make 
                // smaller sum (sorted array)
                else if (nums[left] + nums[right] > target)
                {
                    --right;
                }
                // if sum equals target push triplet to results vector
                // if pointers are duplicates move to next
                else
                {
                    res.push_back({ nums[left], nums[right], nums[i] });
                    ++left; --right;
                    while (left < right && nums[left] == nums[left - 1])
                    {
                        ++left;
                    }
                    while (left < right && nums[right] == nums[right + 1])
                    {
                        --right;
                    }
                }
            }
        }
        // return triplet array
        return res;
    }
};