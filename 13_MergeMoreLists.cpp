#include <iostream>
#include <vector>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool allNull(const vector<ListNode*>& lists){
        for(unsigned int i = 0; i < lists.size(); ++i){
            if(lists[i] != nullptr)return false;
        }
        return true;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *res,*cur;
        res = cur = new ListNode(-1);
        while(!allNull(lists)){
            ListNode* minpNode = nullptr;
            int min  = INT32_MAX, minIndex = 0;
            for(unsigned int i = 0; i < lists.size(); ++i){
                if(lists[i] != nullptr && lists[i]->val < min){
                    minpNode = lists[i];
                    min = minpNode->val;
                    minIndex = i;
                }
            }
            lists[minIndex] = lists[minIndex]->next;
            cur->next = new ListNode(minpNode->val);
            cur = cur->next;
        }
        return res->next;
    }
};

int main()
{
    ListNode N1(1);
    ListNode N2(2);
    ListNode N3(3);
    ListNode N4(4);
    ListNode N5(5);
    ListNode N6(6);
    ListNode N7(7);
    ListNode N8(8);
    ListNode N9(9);

    N1.next = &N2;
    N2.next = &N3;

    N4.next = &N5;
    N5.next = &N6;

    N7.next = &N8;
    N8.next = &N9;

    vector<ListNode*> vec;
    vec.push_back(&N1);
    vec.push_back(nullptr);
    vec.push_back(&N7);

    Solution s;
    ListNode* res = s.mergeKLists(vec);
    while(res){
        cout<<res->val<<' ';
        res = res->next;
    }
    cout<<endl;
    return 0;
}

