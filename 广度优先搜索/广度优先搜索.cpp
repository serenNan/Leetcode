#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(NULL), right(NULL)
    {
    }
    TreeNode(int x) : val(x), left(NULL), right(NULL)
    {
    }
    
};

void levelOrder(TreeNode *root,vector<int> &arr)
{
    queue <TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode *node = q.front();
        q.pop();arr.push_back(node->val);
        if (node->left != nullptr)
            q.push(node->left);
        if(node->right != nullptr)
            q.push(node->right);

    }
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    vector<int> arr;
    levelOrder(root,arr);
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    return 0;

}