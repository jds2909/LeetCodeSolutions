class Solution {
public:
    int search(vector<int>& nums, int target) {
        // left pointer first index
        int left = 0;
        // right pointer last index
        int right = nums.size() - 1;

        // while there is still numbers between pointers
        while (left <= right)
        {
            // mid = (right + left index) / 2
            int mid = (right + left) / 2;
            // if target is greater than mid number
            if (target > nums[mid])
            {
                // discard mid and all numbers to left
                left = mid + 1;
            }
            // if target is less than mid number
            else if (target < nums[mid])
            {
                // discard mid and all numbers to right
                right = mid - 1;
            }
            // if target isnt greater than or less than
            // target found, return index
            else
            {
                return mid;
            }
        }
        // if not found return -1;
        return -1;
    }
};