class Solution {
public:
    void helper(TreeNode* root, string& path, vector<string>& ans) {
        if (!root) return;

        int len = path.length();  // Save current length for backtracking
        path += to_string(root->val);

        if (!root->left && !root->right) {
            ans.push_back(path);  // It's a leaf
        } else {
            path += "->";  // Add arrow only if not leaf
            helper(root->left, path, ans);
            helper(root->right, path, ans);
        }

        path.resize(len);  // Backtrack to previous state
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string path;
        helper(root, path, ans);
        return ans;
    }
};
