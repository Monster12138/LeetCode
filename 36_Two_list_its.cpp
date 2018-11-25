#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *cura = headA, *curb = headB;
        size_t lena, lenb;
        lena = lenb = 1;

        if(cura == nullptr || curb == nullptr)return nullptr;
        while(cura->next || curb->next){
            if(cura->next){
                cura = cura->next;
                lena++;
            }
            if(curb->next){
                curb = curb->next;
                lenb++;
            }
        }
        if(cura != curb) return nullptr;

        cura = headA;
        curb = headB;
        size_t n = (lena > lenb)?(lena - lenb):(lenb - lena);
        if(lena > lenb){
            for(size_t i = 0; i < n; ++i){
                cura = cura->next;
            }
        }
        else{
            for(size_t i = 0; i < n; ++i){
                curb = curb->next;
            }
        }
        while(cura != curb){
            cura = cura->next;
            curb = curb->next;
        }
        return cura;
    }
};

int main()
{
    ListNode n1(1);
    ListNode n2(2);
    ListNode n3(3);
    ListNode n4(4);
    ListNode n5(5);

    n1.next = &n4;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    Solution s;
    ListNode *res = s.getIntersectionNode(&n1, &n2);
    cout << res->val << endl;
    return 0;
}
 
