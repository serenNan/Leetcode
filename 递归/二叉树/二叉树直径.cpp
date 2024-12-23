#include "iostream"
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr)
    {
    }
    TreeNode(int x) : val(x), left(nullptr), right(nullptr)
    {
    }
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right)
    {
    }
};

class Solution
{
  public:
    int ans = 0;
    int deepth(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        int leftDeepth = deepth(root->left);
        int rightDeepth = deepth(root->right);
        ans = max((leftDeepth + rightDeepth + 1), ans);
        return max(leftDeepth, rightDeepth) + 1;
    }
    int diameterOfBinaryTree(TreeNode *root)
    {
        ans = 1;
        deepth(root);
        return ans - 1;
    }
};