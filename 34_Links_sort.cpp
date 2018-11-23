#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* split(ListNode *head){
        ListNode *fast, *slow;
        fast = slow = head;
        if(nullptr == fast || nullptr == fast->next){
            return slow;
        }

        do{
            fast = fast->next->next;
            slow = slow->next;
        }while(nullptr != fast && nullptr != fast->next);

        fast = head;
        while(fast->next && fast->next != slow){
            fast = fast->next;
        }
        
        fast->next = nullptr;
        return slow;
    }

    ListNode* merge(ListNode *l1, ListNode *l2){
        ListNode head(0);
        ListNode *cur = &head;
        while(l1 || l2){
            if(nullptr == l2){
                cur->next = l1;
                l1 = l1->next;
            }
            else if(nullptr == l1){
                cur->next = l2;
                l2 = l2->next;
            }
            else {
                if(l1->val < l2->val){
                    cur->next = l1;
                    l1 = l1->next;
                }
                else {
                    cur->next = l2;
                    l2 = l2->next;
                }
            }
            cur = cur->next;
        }
        cur->next = nullptr;
        return head.next;
    }

    ListNode* sortList(ListNode* head) {
        if(nullptr == head || nullptr == head->next){
            return head;
        }

        ListNode *l1 = head;
        ListNode *l2 = split(head);

        l1 = sortList(l1);
        l2 = sortList(l2);
        return merge(l1, l2);
    }
};

int main()
{
    ListNode n1(6);
    ListNode n2(5);
    ListNode n3(4);
    ListNode n4(3);
    ListNode n5(2);
    ListNode n6(1);

    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    n5.next = &n6;

    Solution s;
    ListNode *res = s.sortList(&n1);
    while(res){
        cout << res->val << " ";
        res = res->next;
    }
    cout << endl;
    return 0;
}

