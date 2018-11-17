#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(NULL == root)return 0;
        int left = 1, right = 1;
        if(root->left)left = maxDepth(root->left) + 1;
        if(root->right)right = maxDepth(root->right) + 1;

        return left>right?left:right;
    }
};
int main()
{
    return 0;
}

