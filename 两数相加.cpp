#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *res,*cur;
        cur = res = (ListNode*)malloc(sizeof(ListNode));

        if(l1 == NULL && l2 == NULL)return NULL;
        else if(l1 == NULL || l2 == NULL)res->next = l1?l1:l2;
        else {
            int carry = 0;
            while(l1&&l2){
                ListNode *newNode = (ListNode*)malloc(sizeof(ListNode));
                newNode->next = NULL;
                cur->next = newNode;
                newNode->val = l1->val + l2->val + carry;

                if(newNode->val > 9){
                    carry = 1;
                    newNode->val %= 10;
                }
                else carry = 0;

                cur = cur->next;
                l1 = l1->next;
                l2 = l2->next;
            }
            ListNode *l = l1?l1:l2;
            while(l||carry)
            {
                ListNode *newNode = (ListNode*)malloc(sizeof(ListNode));
                newNode->next = NULL;
                cur->next = newNode;
                if(l)newNode->val = l->val + carry;
                else newNode->val = 1;

                if(newNode->val > 9){
                    carry = 1;
                    newNode->val %= 10;
                }
                else carry = 0;

                cur = cur->next;
                if(l)l = l->next;
            }
        }
        return res->next;
        
    }
};

int main()
{
    ListNode n1(1);
    ListNode n2(8);
    ListNode n3(3);
    ListNode n4(0);
    ListNode n5(9);
    ListNode n6(9);

    n1.next = &n2;
//    n2.next = &n3;

//    n4.next = &n5;
//    n5.next = &n6;

    Solution s;

    ListNode *res = s.addTwoNumbers(&n1,&n4);

    while(res)
    {
        printf("%d",res->val);
        res = res->next;
    }
    return 0;
}
