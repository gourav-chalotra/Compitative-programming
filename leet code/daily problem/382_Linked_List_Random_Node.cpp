// Medium
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
    int lengthOfList = 0;
    ListNode *SaveHead;
    Solution(ListNode *head)
    {
        ListNode *temp = head;
        SaveHead = head;
        while (temp != NULL)
        {
            temp = temp->next;
        }
    }

    int getRandom()
    {
        int randomIndex = lengthOfList - 1 + 1;
        randomIndex = rand() % randomIndex + 1;
        ListNode *temp = SaveHead;
        int i = 1;
        while (i < randomIndex)
        {
            temp = temp->next;
            i++;
        }
        return temp->val;
    }
};

int main()
{
    return 0;
}