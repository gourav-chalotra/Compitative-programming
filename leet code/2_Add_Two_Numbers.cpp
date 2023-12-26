#include <iostream>
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {

        ListNode *temp = l1;
        int elementCountInL1 = 0, elementCountInL2 = 0;
        while (temp != NULL)
        {
            elementCountInL1++;
            temp = temp->next;
        }
        temp = l2;
        while (temp != NULL)
        {
            elementCountInL2++;
            temp = temp->next;
        }
        ListNode *ptr1, *ptr2;
        if (elementCountInL1 >= elementCountInL2)
        {
            ptr1 = l1, ptr2 = l2;
        }
        else
        {
            ptr1 = l2, ptr2 = l1;
        }
        int carry = 0;
        ListNode *head = new ListNode;
        if (carry + ptr1->val + ptr2->val > 9)
        {
            carry = (carry + ptr1->val + ptr2->val) / 10;
            head->val = (ptr1->val + ptr2->val) % 10;
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        else
        {
            head->val = carry + ptr1->val + ptr2->val;
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        // 2,4,3
        // 5,6,4
        temp = head;
        while (ptr1 != NULL)
        {
            if (ptr2 != NULL)
            {
                if (carry + ptr1->val + ptr2->val > 9)
                {
                    temp->next = new ListNode();
                    temp = temp->next;
                    temp->val = (ptr1->val + ptr2->val + carry) % 10;
                    carry = (carry + ptr1->val + ptr2->val) / 10;
                    temp->next = nullptr;
                }
                else
                {
                    temp->next = new ListNode();
                    temp = temp->next;
                    temp->val = (carry + ptr1->val + ptr2->val);
                    carry = 0;
                }
                ptr2 = ptr2->next;
            }
            else if (carry + ptr1->val > 9)
            {
                temp->next = new ListNode();
                temp = temp->next;
                temp->val = (carry + ptr1->val) % 10;
                carry = (carry + ptr1->val) / 10;
            }
            else
            {
                temp->next = new ListNode();
                temp = temp->next;
                temp->val = (carry + ptr1->val);
                carry = 0;
            }
            ptr1 = ptr1->next;
        }
        while (carry)
        {
            int reminder = carry % 10;
            temp->next = new ListNode(reminder);
            carry /= 10;
        }
        return head;
    }
};
int main()
{
    Solution s;
    ListNode *l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    ListNode *l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);
    ListNode *temp = s.addTwoNumbers(l1, l2);
    ListNode *h1 = temp;
    while (h1 != NULL)
    {
        cout << h1->val << endl;
        h1 = h1->next;
    }
}