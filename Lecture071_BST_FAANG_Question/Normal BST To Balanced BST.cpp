// Time Complexity = O(n)--> traversing whole inorder array
// Space Complexity = O(n)--> storing inorder

void inorder(TreeNode<int>* root, vector<int> &ans)
{
    if(root == NULL)
    return ;

    inorder(root->left, ans);
    ans.push_back(root->data);
    inorder(root->right, ans);
}

TreeNode<int>* inorderToBST(int start, int end,  vector<int>&in ) {
    // base case
    if(start > end)
    return NULL;

    int mid = (start + end)/2;
    TreeNode<int>* root = new TreeNode<int>(in[mid]);
    root->left = inorderToBST(start, mid-1, in);
    root->right = inorderToBST(mid+1, end, in);

    return root;
}
TreeNode<int>* balancedBst(TreeNode<int>* root) {
    // Aman Yadav
    vector<int>inorderVal;
    // store inorder ---> sorted
    inorder(root, inorderVal);

    return inorderToBST(0, inorderVal.size()-1, inorderVal);

}