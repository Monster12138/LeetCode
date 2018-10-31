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
    ListNode* mergeTwoLists(ListNode *l1,ListNode *l2){
       if(l1 == nullptr || l2 == nullptr)return l1?l1:l2;
       ListNode* res = l1, *last = nullptr;
       while(res && l2){
           if(res->val <= l2->val){
               last = res;
               res = res->next;
               continue;
           }
           else{
               ListNode* tmp = l2;
               l2 = l2->next;
               if(last == nullptr){
                   tmp->next = res;
                   l1 = tmp;
                   last = tmp;
               }
               else {
                   tmp->next = res;
                   last = last->next = tmp;
               }
           }
       }
       if(l2 != nullptr)last->next = l2;
       return l1;
    }

    ListNode* recursion(vector<ListNode*>& lists,int left, int right){
        if(left > right)return nullptr;
        else if(left == right)return lists[left];
        else if(left == right - 1)return mergeTwoLists(lists[left], lists[right]);
        else {
            int mid = (left + right)/2;
            ListNode* pleft = recursion(lists, left, mid);
            ListNode* pright = recursion(lists, mid + 1,right);
            return mergeTwoLists(pleft, pright);
        }
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
/*        ListNode *res,*cur;
        res = cur = new ListNode(-1);
        while(1){
            ListNode* minpNode = nullptr;
            int min  = INT32_MAX, minIndex = 0;
            for(unsigned int i = 0; i < lists.size(); ++i){
                if(lists[i] != nullptr && lists[i]->val < min){
                    minpNode = lists[i];
                    min = minpNode->val;
                    minIndex = i;
                }
            }
            if(minpNode == nullptr)break;
            lists[minIndex] = lists[minIndex]->next;
            cur->next = minpNode;
            cur = cur->next;
        }
        return res->next;
*/
        int left = 0,right = lists.size() - 1;
        return  recursion(lists, left, right); 
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

