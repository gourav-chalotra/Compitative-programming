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
    void reorderList(ListNode *head)
    {
        int size = 0;
        ListNode *temp = head;
        while (temp)
        {
            size++;
            temp = temp->next;
        }
        size = (size / 2) + 1;
        cout << "size " << size << endl;
        temp = head;
        while (temp && size != 1)
        {
            temp = temp->next;
            size--;
        }
        cout << "temp->val " << temp->val << endl;
        ListNode *nList = temp->next;
        if(nList == nullptr)
            return;
        cout << "nList->val " << nList->val << endl;
        temp->next = nullptr;
        ListNode*nListCp = nList;
        stack<int>lastELement;
        while (nListCp)
        {
            lastELement.push(nListCp->val);
            nListCp = nListCp->next;
        }
        nListCp = nList;
        while(nListCp)
        {
            nListCp->val = (lastELement.top());
            nListCp = nListCp->next;
            lastELement.pop();
        }
        nListCp = nList;
        while(nListCp)
        {
            cout << nListCp->val <<" ";
            nListCp = nListCp->next;
        }
        nListCp = nList;
        temp = head;
        while (nListCp && temp->next && temp)
        {
            ListNode*tempPtr = temp->next;
            temp->next = nListCp;
            nList = nList->next;
            nListCp->next = tempPtr;
            nListCp = nList;
            temp = temp->next->next;
        }
        
    }
};
int main()
{
    Solution s;
    ListNode *head = new ListNode(1);

    ListNode *temp = head;
    temp = head;
    s.reorderList(head);
    cout << "\n after order are: ";
    while (temp)
    {
        cout << " " << temp->val;
        temp = temp->next;
    }
}