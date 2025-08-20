class Solution {
public:
    int maxArea(vector<int>& height) {
        // define left pointer and right pointer and max area count
        int left = 0, right = height.size() - 1, max_area = 0;
        // while left pointer less than right
        while (left < right)
        {
            // max area calculator
            max_area = max(max_area, min(height[left], height[right]) * (right - left));
            // if left pointer smaller increase it
            if (height[left] < height[right])
            {
                ++left;
            }
            // if right pointer smaller decrease it
            else if (height[left] > height[right])
            {
                --right;
            }
            // if both pointer same size move both
            else
            {
                ++left, --right;
            }
        }
        //return max area
        return max_area;
    }
};