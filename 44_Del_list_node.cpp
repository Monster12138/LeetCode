#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void deleteNode(ListNode* node) {
        if(nullptr == node)return;
        ListNode *tmp = node->next;
        node->val = node->next->val;
        
        node->next = node->next->next;
        free(tmp);
    }
};
int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

