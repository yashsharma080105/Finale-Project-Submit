
class Solution {
public:
    int height(TreeNode* root, int &maxDia) {
        if (root == NULL) return 0;
        int leftHeight = height(root->left, maxDia);
        int rightHeight = height(root->right, maxDia);
        maxDia = max(maxDia, leftHeight + rightHeight);
        return 1 + max(leftHeight, rightHeight);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int maxDia = 0;
        height(root, maxDia);
        return maxDia;
    }
};