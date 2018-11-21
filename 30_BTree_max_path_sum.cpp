#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int maxPathhelper(TreeNode* root, int& max_sum){
        if(root == NULL)return 0;
        int left_sum = maxPathhelper(root->left, max_sum);
        int right_sum = maxPathhelper(root->right, max_sum);
        max_sum = max(max(0,left_sum) + max(0, right_sum) + root->val, max_sum);

        return max(max(left_sum, right_sum) + root->val, 0);
    }

    int maxPathSum(TreeNode* root) {
        if(root == NULL)return 0;
        int max_sum = INT32_MIN;
        maxPathhelper(root, max_sum);
        return max_sum;
    }
};

int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

