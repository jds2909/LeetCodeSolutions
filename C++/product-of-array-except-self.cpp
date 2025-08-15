class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> output;

        // so for nums[i] we want products of all elements before x elements after = output[i]

        if (nums.empty())
        {
            return{};
        }

        // vector to contain the product of all
        vector<int> left_product(nums.size());

        left_product[0] = 1;
        for (int i = 1; i < nums.size(); ++i)
        {
            left_product[i] = left_product[i - 1] * nums[i - 1];
        }

        // nums = [1, 2, 3, 4]
        // after for loop left_product = [1, 1, 2, 6]

        // 1st iteration
        // i = 2
        // right_product = 4
        // left_product = [1, 1, 8, 6]

        // 2nd iteration
        // i = 1
        // right_product = 12
        // left_product = [1, 12, 8, 6]

        // 3rd iteration
        // i = 0
        // right_product = 24
        // left_product = [24, 12, 8, 6]

        int right_product = 1;
        // .size is a size_t unsigned int, subtracting 2 from 1 would cause wraparound to a very large 
        // positive number
        // static cast to convert to a signed int
        // for loop startingf from 2nd right-most element (num size - 2) moving left towards index 0
        for (int i = static_cast<int>(nums.size()) - 2; i >= 0; --i)
        {
            // right product * 
            right_product *= nums[i + 1];
            left_product[i] = left_product[i] * right_product;
        }

        // return final array where each element is product of all other elements
        return left_product;
    }
};