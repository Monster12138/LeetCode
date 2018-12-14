#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
#include <sstream>
#include <queue>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        if(root == nullptr)return 0;
        
        int res;
        TreeNode *cur = root;
        stack<TreeNode *> s;
        while(k && (cur != nullptr || !s.empty())){
            while(cur){
                s.push(cur);
                cur = cur->left;
            }
            
            cur = s.top();
            res = cur->val;
            s.pop();
            cout << k << endl;
            k--;
           
            cur = cur->right;
        }
        return res;
    }
};

int main()
{
    TreeNode N1(3);
    TreeNode N2(1);
    TreeNode N3(2);
    TreeNode N4(4);
    N1.left = &N2;
    N1.right = &N4;
    N2.right = &N3;

    Solution s;
    cout << s.kthSmallest(&N1,1) << endl;
    return 0;
}


