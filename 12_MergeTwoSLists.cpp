#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
       ListNode *res, *cur;
       res = cur = (ListNode*)malloc(sizeof(ListNode));
       res->next = nullptr;
       while(l1||l2){
           cur->next = (ListNode*)malloc(sizeof(ListNode));
           cur->next->next = nullptr;
           int x1,x2;
           x1 = x2 = INT32_MAX;
           if(l1)x1 = l1->val;
           if(l2)x2 = l2->val;
           cur->next->val = x1<x2?x1:x2;
           if(x1 < x2)l1=l1->next;
           else l2 = l2->next;
            
           cur = cur->next;
       }
       return res->next;
    }
};

int main()
{
    ListNode N1(1);
    ListNode N2(3);
    ListNode N3(5);

    ListNode N4(2);
    ListNode N5(4);
    ListNode N6(6);

    N1.next = &N2;
    N2.next = &N3;

    N4.next = &N5;
    N5.next = &N6;

    Solution s;
    ListNode* res = s.mergeTwoLists(nullptr,nullptr);
    while(res){
        cout << res->val << ' ';
        res = res->next;
    }

    cout<<endl;
    return 0;
}

