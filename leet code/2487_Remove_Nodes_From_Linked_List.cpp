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
    int RemoveNode(ListNode *head, ListNode *prev = nullptr)
    {
        if (head->next == nullptr)
            return head->val;
        int maxVal = max(head->val, (RemoveNode(head->next, head)));
        if (maxVal != head->val)
        {
            if (prev == nullptr && head->val < maxVal)
            {
                head = head->next;
            }
            else
                prev->next = head->next;
        }
        return maxVal;
    }
    ListNode *removeNodes(ListNode *head)
    {
        RemoveNode(head);
        if (head->next != nullptr && head->next->val > head->val)
        {
            head = head->next;
        }
        return head;
    }
};

int main()
{
    Solution s;
    // 5,2,13,3,8
    ListNode *head = new ListNode(1);
    head->next = new ListNode(12);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(5);
    // head->next->next->next->next = new ListNode(6);

    head = s.removeNodes(head);

    ListNode *temp = head;
    while (temp != nullptr)
    {
        cout << temp->val << endl;
        temp = temp->next;
    }
}