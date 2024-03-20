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
    ListNode *mergeInBetween(ListNode *list1, int a, int b, ListNode *list2)
    {
        int i = 1;
        ListNode*temp = list1,*start = NULL,*end = NULL;

        while ((i<=a || i <= b+1) && temp!=nullptr)
        {
            if(i == a)
            {
                start = temp;
            }
            end = temp;
            temp = temp->next;
            i++;
        }
        if(end)
        {
            end = end->next;
        }
        start->next = list2;
        temp = list2;
        while(temp->next)
        {
            temp=temp->next;
        }
        temp->next = end;
        return list1;
    }
};
int main()
{

}