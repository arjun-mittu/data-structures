/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    /* bool solve(TreeNode *root,int minv=INT_MIN,int maxv=INT_MAX){
        if(root==NULL) return true;
        if(root->val>=minv && root->val<=maxv && solve(root->left,minv,root->val) && solve(root->right,root->val,maxv)){
            return true;
        }
        return false;
    }*/
    bool solve(TreeNode *root, TreeNode *minN, TreeNode *maxN)
    {
        if (root == NULL)
            return true;
        if (minN && root->val <= minN->val || maxN && root->val >= maxN->val)
            return false;
        return solve(root->left, minN, root) && solve(root->right, root, maxN);
    }
    bool isValidBST(TreeNode *root)
    {
        return solve(root, NULL, NULL);
    }
};