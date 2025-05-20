class Solution {
public:
    int levels(TreeNode* root){
        if(root == NULL) return 0;
        return 1 + max(levels(root->left), levels(root->right));
    }

    void nthLevel(TreeNode* root, int curr, int level, vector<int>& v){
        if(root == NULL) return;
        if(curr == level){
            v.push_back(root->val);
            return;
        }
        nthLevel(root->left, curr + 1, level, v);
        nthLevel(root->right, curr + 1, level, v);
    }

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        int n = levels(root);
        for(int i = 1; i <= n; i++){
            vector<int> v;
            nthLevel(root, 1, i, v);
            // Reverse the level if it's an even-numbered level
            if(i % 2 == 0){
                reverse(v.begin(), v.end());
            }
            ans.push_back(v);
        }
        return ans;
    }
};
