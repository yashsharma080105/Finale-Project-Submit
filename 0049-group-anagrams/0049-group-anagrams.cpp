class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& arr) {
        // Final result: a vector of groups of anagram strings
        vector<vector<string>> ans;

        // Hash map to group words by their sorted (anagram) form
        unordered_map<string, vector<string>> mp;

        // Iterate over each string in the input array
        for (string str : arr) {
            // Make a copy of the string to sort (original string should remain unchanged)
            string lexo = str;

            // Sort the string to get the canonical anagram form
            sort(lexo.begin(), lexo.end());

            // If this sorted version is not in the map, create a new group
            if (mp.find(lexo) == mp.end()) {
                vector<string> v;
                v.push_back(str);
                mp[lexo] = v;
            } 
            else {
                // If the sorted version exists, add the original string to its group
                mp[lexo].push_back(str);
            }
        }

        // Iterate through the map and collect all the grouped anagrams
        for (auto x : mp) {
            vector<string> v = x.second;
            ans.push_back(v);
        }

        // Return the grouped anagrams
        return ans;
    }
};
