#include<bits/stdc++.h>
using namespace std;

 struct ListNode {
    int val;
      ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr)
            return head;
        ListNode*slow = head;
        ListNode*fast = head->next;
        while(slow && fast)
        {
            if(slow->val == fast->val)
            {
                slow->next = fast->next;
                fast = fast->next;
            }
            else
            {
                slow = fast;
                fast = fast->next;
            }
        }
        return head;
    }
};
int main()
{

}