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
    map<int, map<int,multiset<int>>>mms;
    void setPosition(TreeNode *root, int Pos,int level)
    {
        if (root == nullptr)
            return;
        cout << root->val << endl;
        mms[Pos][level].insert(root->val);
        setPosition(root->right, Pos + 1,level+1);
        setPosition(root->left, Pos - 1,level+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        vector<vector<int>> ans;
        setPosition(root, 0,0);
        for (auto i : mms)
        {
            vector<int>temp;
            for(auto j : i.second)
            {
                for(auto k : j.second)
                {
                    temp.push_back(k);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};

int main()
{
    Solution s;
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    s.verticalTraversal(root);
}