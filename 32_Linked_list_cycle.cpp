#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *fast, *slow;
        if(nullptr == head || nullptr == head->next)return false;
        fast = slow = head;
        do{
            fast = fast->next->next;
            slow = slow->next;
        }while(fast && fast->next && fast != slow);

        if(fast == slow)return true;
        else return false;
    }
};

int main()
{
    return 0;
}

