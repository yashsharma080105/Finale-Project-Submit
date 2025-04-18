class Solution {
private:
    void solve(string digit, string output, int index, vector<string>& ans, string mapping[]) {
        // Base case: if the current index is beyond the last digit, save the current output
        if(index >= digit.length()) {
            ans.push_back(output);
            return;
        }
        
        int number = digit[index] - '0'; // Convert the character digit to an integer
        string value = mapping[number];  // Get the corresponding letters for the digit
        
        // Iterate over each letter in the value string
        for(int i = 0; i < value.length(); i++) {
            output.push_back(value[i]); // Append the current letter to the output
            solve(digit, output, index + 1, ans, mapping); // Recur for the next digit
            output.pop_back(); // Backtrack: remove the last added letter to try the next one
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        
        if(digits.length() == 0)
            return ans;
        
        string output = "";
        int index = 0;
        
        string mapping[10] = {"", "", "abc", "def", "ghi", "jkl",
                              "mno", "pqrs", "tuv", "wxyz"};
        
        solve(digits, output, index, ans, mapping);
        return ans;
    }
};

