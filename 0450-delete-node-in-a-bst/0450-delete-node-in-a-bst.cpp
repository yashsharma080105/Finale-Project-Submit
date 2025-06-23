
class Solution {
public:
    TreeNode* iop(TreeNode* root){
        TreeNode* pred = root->left;
        while(pred->right){
            pred = pred->right;
        }
        return pred;
    }

    TreeNode* ios(TreeNode* root){
        TreeNode* suc = root->right;
        while(suc->right){
            suc = suc->right;
        }
        return suc;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL) return NULL;
        if(root->val == key){
            // Case 1 : No child
            if(root->left==NULL && root->right==NULL) return NULL;

            // Case 2 : 1 Child
            if(root->left==NULL || root->right==NULL){
                if(root->left!=NULL) return root->left;
                else return root->right;
            }

            // Case 3 : 2 child nodes
            if(root->left!=NULL && root->right!=NULL){
                //replace the roots eith its inorder predecessor/successor
                // after replacing delete the pred/suc
                TreeNode* pred = iop(root);
                root->val = pred->val;
                root -> left  = deleteNode(root->left,pred->val);
            }
        }


        
        else if(root->val > key){ //go left
            root -> left  = deleteNode(root->left,key);
        } 
        else{ // root->val < key : go right
            root->right = deleteNode(root->right,key);
        }
        return root;
    }
};