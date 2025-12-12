class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        // 1 vector contains combined vectors
        vector<int> fullList;
        // calculate size of combined vector and reserve
        size_t totalSize = 0;
        for (const auto& x : matrix)
        {
            totalSize += x.size();
        }
        fullList.reserve(totalSize);
        // insert each vector into fullList vector
        for (const auto& x : matrix)
        {
            fullList.insert(fullList.end(), x.begin(), x.end());
        }

        // if fullList matrix failed to fill or is just empty return false;
		if (fullList.empty())
        {
            return false;
        }

        // set pointers
        int left = 0;
        int right = fullList.size() - 1;
        int mid;

        // must be equal to as last element when pointers meet needs to be checked
        while (left <= right)
        {
            mid = (left + right) / 2;
            // early return if found
            if (fullList[mid] == target)
            {
                return true;
            }
            // if midpoint value > target discard right half
            else if (fullList[mid] > target)
            {
                right = mid - 1;
            }
            // else (midpoint value < target) discard left half
            else
            {
                left = mid + 1;
            }
        }
		// if not found return false
        return false;
    }
};