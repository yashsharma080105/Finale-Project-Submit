class Solution {
public:
    TreeNode* build(vector<int>& post, int pslo, int pshi, vector<int>& in, int inlo, int inhi) {
        if (pslo > pshi) return NULL;

        TreeNode* root = new TreeNode(post[pshi]);  // corrected bracket
        if (pslo == pshi) return root;

        int i = inlo;
        while (i <= inhi) {
            if (in[i] == post[pshi]) break;  // use post[pshi], not pre[pshi]
            i++;
        }

        int leftCount = i - inlo;

        root->left = build(post, pslo, pslo + leftCount - 1, in, inlo, i - 1);
        root->right = build(post, pslo + leftCount, pshi - 1, in, i + 1, inhi);  // pshi - 1 because pshi is root

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = postorder.size();
        return build(postorder, 0, n - 1, inorder, 0, n - 1);
    }
};


