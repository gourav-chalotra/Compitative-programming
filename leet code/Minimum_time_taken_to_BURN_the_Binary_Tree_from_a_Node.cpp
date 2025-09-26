#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    // map child with parent.
    void mapChildToParent(unordered_map<TreeNode *, TreeNode *> &mp, TreeNode *root)
    {
        if (root == nullptr)
            return;

        if (root->left)
        {
            mp[root->left] = root;
            mapChildToParent(mp, root->left);
        }
        if (root->right)
        {
            mp[root->right] = root;
            mapChildToParent(mp, root->right);
        }
    }

    TreeNode *findTarget(TreeNode *root, int target)
    {
        TreeNode *left = nullptr, *right = nullptr;
        if (root == nullptr)
            return nullptr;
        if (root->data == target)
            return root;
        if (root->left)
            left = findTarget(root->left, target);
        if (root->right)
            right = findTarget(root->right, target);

        if (left)
            return left;
        if (right)
            return right;
        return nullptr;
    }
    int timeToBurnTree(TreeNode *root, int target)
    {
        int BurnTime = 0;
        unordered_map<TreeNode *, TreeNode *> CPM;
        mapChildToParent(CPM, root);


        TreeNode *targetNode = findTarget(root, target);

        // visited track
        unordered_map<TreeNode *, bool> visit;

        queue<TreeNode *> q;
        q.push(targetNode);
        while (!q.empty())
        {
            vector<TreeNode *> v;
            while (!q.empty())
            {
                v.push_back(q.front());
                q.pop();
            }
            bool nextBurnNodePresent = false;
            for (auto i : v)
            {
                visit[i] = true;
                if (i->left && visit.find(i->left) == visit.end())
                {
                    q.push(i->left);
                    nextBurnNodePresent = true;
                }
                if (i->right && visit.find(i->right) == visit.end())
                {
                    q.push(i->right);
                    nextBurnNodePresent = true;
                }
                if (CPM[i] && visit.find(CPM[i]) == visit.end())
                {
                    q.push(CPM[i]);
                    nextBurnNodePresent = true;
                }
            }
            if (nextBurnNodePresent)
                BurnTime++;
        }
        return BurnTime;
    }
};

int main()
{
    TreeNode *root = new TreeNode(1);

    // Level 1
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    // Level 2
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(4);

    // Target
    int target = 4;
    Solution s;
    cout << s.timeToBurnTree(root, target);
}
