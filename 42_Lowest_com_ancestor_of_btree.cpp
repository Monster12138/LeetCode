#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

static const auto _=[]{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {  
        TreeNode *cur = root;
        while(1){
            if(cur==nullptr) return nullptr;
            if(p==cur || q==cur) return cur;
            else if(cur->val < p->val && cur->val < q->val)
                cur = cur->right;
            else if(cur->val > p->val && cur->val > q->val)
                cur = cur->left;
            else return cur;
        }
    }
};

int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

