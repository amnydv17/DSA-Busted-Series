int solve(BinaryTreeNode<int>* root,int& count, int k)
{
    // base case
    if(root == NULL)
    return -1;

    // Left
    int left = solve(root->left, count, k);

    if(left != -1)
    {
        return left;
    }

    // Node
    count++;
    if(count == k)
    {
        return root->data;
    }

    // Right
    solve(root->right, count, k);
}

int kthSmallest(BinaryTreeNode<int>* root, int k) {
    // Aman Yadav
    int count = 0;
    int ans = solve(root, count, k);
    return ans;
}