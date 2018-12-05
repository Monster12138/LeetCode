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
    /*
    bool is_in_tree(TreeNode *root, TreeNode *node){
        if(nullptr == root)return false;
        if(node == root)return true;
        stack<TreeNode *> s;
        TreeNode *cur = root;
        while(cur || !s.empty()){
            while(cur){
                s.push(cur);
                cur = cur->left;
            }
            cur = s.top();
            s.pop();
            if(cur == node)return true;
            
            cur = cur->right;
        }
        
        return false;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(nullptr == root)return nullptr;
        TreeNode *cur = root;
        while(cur){
            if(is_in_tree(cur->left, p) && is_in_tree(cur->left, q))cur = cur->left;
            else if(is_in_tree(cur->right, p) && is_in_tree(cur->right, q))cur = cur->right;
            else return cur;
        }
        return root;
    }
    */
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || q == root || p == root)
            return root;
        TreeNode *left = lowestCommonAncestor(root->left, p ,q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);
        
        if(left && right)return root;
        return left?left:right;
    }
};

int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

