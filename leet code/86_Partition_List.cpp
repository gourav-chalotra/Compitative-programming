
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
    ListNode *partition(ListNode *head, int x)
    {
        ListNode *temp = head;
        while (temp != nullptr)
        {
            // cout << temp->val;
            temp = temp->next;
        }
        // smaller then x Linkedlist
        ListNode* smallNodeHead = new ListNode(0);
        ListNode* sNH = smallNodeHead;
        ListNode* largeNodeHead = new ListNode(0);
        ListNode* lNH = largeNodeHead;
        temp = head;
        while(temp!=nullptr)
        {
            if(temp->val < x)
            {
                sNH->next = new ListNode(temp->val);
                sNH = sNH->next;
            }
            else
            {
                lNH->next = new ListNode(temp->val);
                lNH = lNH->next;
            }
            temp = temp->next;
        }
        sNH->next = largeNodeHead->next;

        return smallNodeHead->next;
    }
};

int main()
{
    ListNode *head = new ListNode(1);
    ListNode *second = new ListNode(4);
    ListNode *theird = new ListNode(3);
    ListNode *fourth = new ListNode(2);
    ListNode *fifit = new ListNode(5);
    ListNode *six = new ListNode(2);
    head->next = second;
    second->next = theird;
    theird->next = fourth;
    fourth->next = fifit;
    fifit->next = six;


    Solution s;
    ListNode *newHead = s.partition(head, 3);
    while (newHead != nullptr)
    {
        cout << newHead->val << endl;
        newHead = newHead->next;
    }
}