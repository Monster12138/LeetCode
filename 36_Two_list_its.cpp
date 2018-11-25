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
        lena = lenb = 0;
    }
};

int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

