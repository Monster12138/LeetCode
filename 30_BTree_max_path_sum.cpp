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
    int maxPathSum(TreeNode* root) {
        if(root == NULL)return 0;
        int max = root->val;
        int leftnum = maxPathSum(root->left);
        int rightnum = maxPathSum(root->right);
        if(leftnum > rightnum && leftnum > 0)return max + leftnum;
        if(leftnum < rightnum && rightnum > 0)return max + rightnum;
        else return max;
    }
};

int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

