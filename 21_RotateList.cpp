#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL)return NULL;
        ListNode *slow = head, *fast = head;
        int length = 0;
        while(k--){
            if(fast->next == NULL){
                fast = head;
                k = k%length;
            }
            else{
                fast = fast->next;
                length++;
            }
        }
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next;
        }
        fast->next = head;
        head = slow->next;
        slow->next = NULL;
        return head;
    }
};

int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

