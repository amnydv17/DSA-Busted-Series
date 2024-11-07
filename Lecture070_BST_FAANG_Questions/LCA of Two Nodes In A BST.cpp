TreeNode *LCAinaBST(TreeNode *root, TreeNode *P, TreeNode *Q)
{
    // Aman Yadav
    // Recursive Solution

    // if(root == NULL)
    // return NULL;

    // if(root->data < P->data && root->data < Q->data)
    // return LCAinaBST(root->right, P, Q);

    // if(root->data > P->data && root->data > Q->data)
    // return LCAinaBST(root->left, P, Q);

    // return root;


    // Itrative Solution
    while(root != NULL)
    {
        if(root->data < P->data && root->data < Q->data)
        root = root->right;

        else if(root->data > P->data && root->data > Q->data)
        root = root->left;

        else{
            return root;
        }
    }
}