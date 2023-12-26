
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//  Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int>allElement;
        for(int i = 0; i < lists.size(); i++)
        {
            ListNode*pt = lists[i];
            while(pt!=nullptr)
            {
                allElement.push_back(pt->val);
                pt = pt->next;
            }
        }
        sort(allElement.begin(),allElement.end());
        ListNode *newHead = new ListNode();
        ListNode *tempNPtr = newHead;
        for(auto i:allElement)
        {
            tempNPtr->next = new ListNode(i);
            tempNPtr = tempNPtr->next;
        }
        return newHead->next;
    }
};
