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
    bool find(vector<ListNode*>addsNode, ListNode*add)
    {
        int i=0;
        for(;i<addsNode.size();i++)
        if(addsNode[i]==add)return true;

        return false;
    }
    bool hasCycle(ListNode *head)
    {
        // if (head == nullptr || head->next == nullptr)
        //     return false;
        ListNode *Ptr = head;
        vector<ListNode*> addressOfNodes;
        while (Ptr != NULL)
        {
            if (find(addressOfNodes, Ptr))
            {
                return true;
            }
            else
                addressOfNodes.push_back(Ptr);
        }
        return false;
    }
};
int main()
{
    return 0;
}