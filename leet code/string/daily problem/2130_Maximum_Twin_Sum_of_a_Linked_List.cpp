#include<iostream>
#include<vector>
#include<stdio.h>
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
    int pairSum(ListNode* head)
    {
        vector<int>v1;
        ListNode*temp = head;
        while(temp!=nullptr)
        {
            v1.push_back(temp->val);
            temp = temp->next;
        }
        int maxTwins = -1000;
        int i = 0;
        int size = v1.size();
        while(i<=(size/2)-1)
        {
            if(maxTwins < v1[i]+v1[size-1-i])
            {
                maxTwins = v1[i]+v1[size-1-i];
            }
            i++;
        }
        return maxTwins;
    }
};
int main()
{
    Solution s;
    ListNode*head = new ListNode(1);
    ListNode*second = new ListNode(100000);
    head->next = second;
    // ListNode*third = new ListNode(2);
    // second->next = third;
    // ListNode*four = new ListNode(3);
    // four->next = third;
    cout << s.pairSum(head);
    return 0;
}