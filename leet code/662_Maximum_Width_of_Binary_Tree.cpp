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
    int widthOfBinaryTree(TreeNode *root)
    {
        int index = 0, maxWidth = 0;
        queue<pair<TreeNode *, int>> q;
        q.push({root, index});
        while (!q.empty())
        {
            pair<TreeNode *, int> temp = q.front();
            int min = temp.second;
            int lastVal = temp.second;
            cout << "\nq: ";
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                pair<TreeNode *, int> last = q.front();
                lastVal = last.second;
                cout << last.second << " ";
                if(last.first->left)
                {
                    q.push({last.first->left, 2*(last.second-min)+1});
                }
                if(last.first->right)
                {
                    q.push({last.first->right, 2*(last.second-min)+2});
                }
                q.pop();

            }
            cout << endl;
            maxWidth = max(lastVal-min+1,maxWidth);
        }
        return maxWidth;
    }
};

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(5);
    root->left->left->left = new TreeNode(6);
    root->right->right = new TreeNode(9);
    root->right->right->left = new TreeNode(7);

    Solution s;
    cout << "max width: " << s.widthOfBinaryTree(root);
}