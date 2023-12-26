#include <iostream>
#include <vector>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    int check(ListNode *temp, vector<ListNode *> t)
    {
        for (int i = 0; i < t.size(); i++)
        {
            if (t.at(i) == temp)
            {
                return i;
            }
        }
        return -1;
    }
    ListNode *detectCycle(ListNode *head)
    {
        int pos = -1;
        ListNode *tempNode = head;
        vector<ListNode *> t;
        while (tempNode != NULL)
        {
            int n = check(tempNode, t);
            if (n > -1)
            {
                pos = n;
                return tempNode;
            }
            t.push_back(tempNode);
            tempNode = tempNode->next;
        }
        return NULL;
    }
};

int main()
{

    return 0;
}