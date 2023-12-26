#include<iostream>
#include<vector>
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode*createNode(int val)
    {
        ListNode*head = new ListNode(val);
        head->next = nullptr;
        return head;
    }
    ListNode* swapNodes(ListNode* head, int k) 
    {
        ListNode* temp = head;
        std::vector<int>v1;
        while(temp!=nullptr)
        {
            v1.push_back(temp->val);
            temp = temp->next;
        }
        
        std::cout<<std::endl;
        int sz = v1.size();
        int t;
        t = v1[k-1];
        v1[k-1] = v1[sz-k];
        v1[sz-k] = t;
        head = new ListNode(0);
        temp = head;
        for(int i = 0; i < v1.size();i++)
        {
            temp->val = v1.at(i);
            temp->next = new ListNode;
            temp = temp->next;
        }
        temp = head;
        while(temp->next->next != nullptr)
            temp = temp->next;
        temp->next = nullptr;

        return head;
    }
};
int main()
{
    Solution s;
    ListNode*head = new ListNode;
    head->val = 3;
    ListNode*secound = new ListNode;
    head->next = secound;
    secound->val = 45;
    
    ListNode*theird = new ListNode;
    secound->next = theird;
    theird->val = 5;

    head = s.swapNodes(head,3);
    ListNode *temp = head;
    while(temp!=nullptr)
    {
        std::cout << temp->val << " ";
        temp = temp->next;
    }
        

}