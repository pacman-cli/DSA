class Solution
{
public:
  vector<int> preorderTraversal(TreeNode *root)
  {
    vector<int> result;
    preorder(root, result);
    return result;
  }

private:
  void preorder(TreeNode *node, vector<int> &result)
  {
    if (node != NULL)
    {
      result.push_back(node->val);
      preorder(node->left, result);
      preorder(node->right, result);
    }
  }
};
