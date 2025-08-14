#include <unordered_map>

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // hash map groups, key = sorted version of word value = og word
        unordered_map<string, vector<string>> groups;
        // for all strings in strs
        for (const auto& str : strs)
        {
            //copy of original string to not edit original
            string tmp{str};
            // sort string in alphabetical order to generate key for anagram
            sort(tmp.begin(), tmp.end());
            // insert original string to the vector mapped to sorted key
            groups[tmp].emplace_back(str);
        }
        // result vector anagrams
        // kvp first is the sorted key of anagram
        // kvp second is the original string vector
        vector<vector<string>> anagrams;
        // iterate over each 
        for (const auto& kvp : groups)
        {
            // new vector to not edit group
            vector<string> group;
            // for each original string value 
            for (const auto& str : kvp.second)
            {
                //copy to group vector
                group.emplace_back(str);
            }
            //sort alphabetically
            sort(group.begin(), group.end());
            // moves group vector to the end of anagrams vector
            anagrams.emplace_back(move(group));
        }
        // output all grouped anagrams
        return anagrams;
    }
};