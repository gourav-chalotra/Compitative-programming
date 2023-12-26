#include <iostream>
#include <vector>
using namespace std;
//  Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//  Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    TreeNode *sortedListToBST(ListNode *head)
    {
        vector<int> v1;
        ListNode *temp = head;
        int i = 0;
        while (temp != NULL)
        {
            v1.push_back(temp->val);
            cout << "v1.at(i): " << v1.at(i) << endl;
            i++;
            temp = temp->next;
        }
        int mid = v1.size() / 2;
        if (v1.size() % 2)
        {
            int root = mid;
            TreeNode ROOT(v1.at(root));
            cout << "root left: " << ROOT.left << endl;
            cout << "root right: " << ROOT.right << endl;
            cout << "root.val: " << ROOT.val << endl;
            ROOT.left = nullptr;
            ROOT.right = nullptr;
            cout << "mid: " << v1[mid] << endl;
            int countLeft = mid - 1;

            while (countLeft >= 0)
            {
                TreeNode *tempLeft = &ROOT;
                cout << "tempLeft->left: " << tempLeft->left << endl;
                cout << "v1[countLeft]: " << v1[countLeft] << endl;
                TreeNode element(v1[countLeft]);
                cout << "element.val: " << element.val << endl;
                cout << "element.left: " << element.left << endl;

                while (tempLeft->left != nullptr)
                {
                    cout << "check " << endl;
                    tempLeft = tempLeft->left;
                }
                tempLeft->left = &element;
                countLeft--;
            }
        }
    }
};
int main()
{
    Solution s;
    ListNode *head;
    ListNode first(-10);
    ListNode secound(-3);
    ListNode theird(0);
    ListNode fourth(5);
    ListNode five(9);

    first.next = &secound;
    secound.next = &theird;
    theird.next = &fourth;
    fourth.next = &five;

    head = &first;

    s.sortedListToBST(head);
    return 0;
}