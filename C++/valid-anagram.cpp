#include <string>
#include <unordered_map>

using namespace std;

class Solution 
{ 
public:
    bool isAnagram(string s, string t)
    {
        // early check if sizes are different cant be anagram so return false
        if (s.size() != t.size()) 
        {
            return false;
        }

        //create unordered_map to take char and convert to int to count each char
        unordered_map<char, int> count;
        //iterate through all char in string s and add to unordered_map
        for (const auto& c: s) 
        {
            ++count[c];
        }
        // do the same for string t but decrease rather than increment, if any count
        // goes below 0 then early exit with false
        for (const auto& c: t) 
        {
            --count[c];
            if (count[c] < 0) 
            {
                return false;
            }
        }
        // otherwise return true
        return true;
    }
};