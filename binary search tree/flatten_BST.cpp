/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void solve(TreeNode *A)
{
    if (A == NULL || (A->left == NULL && A->right == NULL))
        return;
    if (A->left != NULL)
    {
        solve(A->left);
        TreeNode *temp = A->right;
        A->right = A->left;
        A->left = NULL;
        TreeNode *t = A->right;
        while (t->right != NULL)
            t = t->right;
        t->right = temp;
    }
    solve(A->right);
}
TreeNode *Solution::flatten(TreeNode *A)
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    solve(A);
    return A;
}
