#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr || head->next == nullptr)return head;
        /*
        ListNode *cur = head, *_next = head->next;
        
        cur->next = nullptr;
        while(_next){
            ListNode *tmp = _next->next;
            _next->next = cur;
            cur = _next;
            _next = tmp;
        }
        
        return cur;
        */
        
        ListNode *p = head;
        head = reverseList(p->next);
        p->next->next = p;
        p->next = nullptr;
        
        return head;
    }
};

int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

