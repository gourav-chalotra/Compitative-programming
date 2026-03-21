#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        if(!head){
            return head;
        }
        ListNode*curr = head, *prev = nullptr, *next = nullptr;
        while(curr)
        {
            next = curr->next;
            if(next == nullptr)
                break;
            else if (next->val == curr->val)
            {
                if(curr == head)
                {
                    while(head != nullptr && head->val == next->val)
                        head = head->next;
                    curr = head;
                    continue;
                }
                else
                {
                    while(next != nullptr && next->val == curr->val)
                        next = next->next;
                    curr = next;
                    prev->next = next;
                    continue;
                }
            }
            prev = curr;
            curr = curr->next;
        }
        return head;
    }
};
int main()
{
    ListNode* head = new ListNode(1);
    head->next = new ListNode(1);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(2);
    head->next->next->next->next = new ListNode(3);
    Solution s;
    ListNode*temp  = s.deleteDuplicates(head);
    while(temp){
        cout << temp->val << endl;
        temp = temp->next;
    }
    
}