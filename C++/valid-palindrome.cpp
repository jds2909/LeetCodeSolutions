class Solution {
public:
    bool isPalindrome(string s) {
        // left index val
        int i = 0;
        // right index val
        int j = s.length() - 1;

        //while left index is less than right
        while (i < j)
        {
            //if s[i] not alphanumeric 
            if (!isalnum(s[i]))
            {
                //increment to next index
                ++i;
            }
            //if s[j] not alphanumeric
            else if (!isalnum(s[j]))
            {
                //decrease to next index
                --j;
            }
            // if 1st alphanumeric i value != 1st alphanumeric j val
            else if (tolower(s[i]) != tolower(s[j]))
            {
                // return false not palindrome
                return false;
            }
            // else increment each pointer
            else
            {
                ++i, --j;
            }
        }
        // valid palindrome
        return true;
    }
};