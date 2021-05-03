int dist_(Node *root, int k, int dist)
{
    if (root == NULL)
        return -1;
    if (root->data == k)
        return dist;
    int left = dist_(root->left, k, dist + 1);
    if (left != -1)
        return left;
    return dist_(root->right, k, dist + 1);
}