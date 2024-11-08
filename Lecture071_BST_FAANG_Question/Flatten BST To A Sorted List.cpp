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


TreeNode<int>* flatten(TreeNode<int>* root)
{
    // Aman Yadav
    vector<int>inorderVal;
    // store inorder ---> sorted
    inorder(root, inorderVal);
    int n = inorderVal.size();

    TreeNode<int>* newRoot = new TreeNode<int>(inorderVal[0]);
    TreeNode<int>* curr = newRoot;

    for(int i=1; i<n; i++)
    {
        TreeNode<int>* temp = new TreeNode<int>(inorderVal[i]);
        curr->left = NULL;
        curr->right = temp;
        curr = temp;
    }

    curr->left = NULL;
    curr->right = NULL;

    return newRoot;

}
