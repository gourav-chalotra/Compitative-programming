#include <bits/stdc++.h>
using namespace std;
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
    TreeNode *head;
    int recursive(TreeNode *root, int sum = 0)
    {
        if (root == nullptr)
            return sum;
            sum = max(recursive(root->left, sum + 1),sum);
            cout << "left sum = " << sum <<" node value: " << root->val << endl;
            sum = max(recursive(root->right, sum + 1),sum);
            cout << "right sum = " << sum <<" node value: " << root->val << endl;
            return sum;
    }
    void display(TreeNode*root)
    {
        if(root == nullptr)
        {
            return;
        }
        cout << "root: " << root->val << endl;
        display(root->left);
        display(root->right);

    }
    int diameterOfBinaryTree(TreeNode *root)
    {
        head = root;
        display(root);
        cout << "left : "<< recursive(root->left) << endl;
        cout << "right : "<< recursive(root->right) << endl;
    }
};
int main()
{
    TreeNode *root = new TreeNode();
    root->val = 1;
    root->right = new TreeNode();
    root->right->val = 3;
    root->right->right = nullptr;
    root->right->left = nullptr;
    root->left = new TreeNode();
    root->left->val = 2;
    root->left->right = new TreeNode();
    root->left->right->val = 5;
    root->left->right->left = nullptr;
    root->left->right->right = nullptr;
    root->left->left = new TreeNode();
    root->left->left->val = 4;
    root->left->left->left = nullptr;
    root->left->left->right = nullptr;
    

    Solution s;

    s.diameterOfBinaryTree(root);
}