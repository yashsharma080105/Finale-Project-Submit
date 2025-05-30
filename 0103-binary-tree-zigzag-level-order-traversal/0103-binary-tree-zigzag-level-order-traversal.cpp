class Solution {
public:
    int levels(TreeNode* root){
        if(root==NULL) return 0;
    return 1+ max(levels(root->left), levels(root->right));
    }

    void nthlevel(TreeNode* root,int curr, int level , vector<int>& v ){
        if(root==NULL) return;
        if(curr==level){
            v.push_back(root->val);
            return;
        }
        nthlevel(root->left, curr+1, level, v);
        nthlevel(root->right, curr+1 , level, v);
    }
    

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        int n = levels(root);
        for(int i=1;i<=n;i++){
            vector<int> v;
            nthlevel(root, 1, i ,v);
            if(i%2==0){
                reverse(v.begin(),v.end());
            }
            ans.push_back(v);
            
        }
        return ans;
    }
};
