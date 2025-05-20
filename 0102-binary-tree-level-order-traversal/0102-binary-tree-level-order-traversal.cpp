
class Solution {
public:
    int levels(TreeNode* root){
        if(root==NULL) return 0;
        return 1 + max(levels(root->left), levels(root->right));
    }
    void nthLevel(TreeNode* root, int curr, int level, vector<int>& v){
        if(root==NULL) return;   //base case
        if(curr==level){
            v.push_back(root->val);  //root
            return;
        }
        nthLevel(root->left,curr+1,level,v);   //left
        nthLevel(root->right,curr+1,level,v);  // right
    }
    void lOrder(TreeNode* root, vector<vector<int>>& ans){
        int n = levels(root);
        for(int i=1;i<=n;i++){
            vector<int> v;
            nthLevel(root,1,i,v);
            ans.push_back(v);
            cout<<endl;
        }
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        lOrder(root,ans);
        return ans;
    }
};