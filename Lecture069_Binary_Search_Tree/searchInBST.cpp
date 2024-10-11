bool searchInBST(BinaryTreeNode<int> *root, int x) {
    // Aman Yadav
    // Approach-1--> Recursive
    // if(root == NULL)
    // {
    //     return false;
    // }
    // if(root->data == x)
    // {
    //     return true;
    // }

    // if(root->data > x)
    // {
    //     // left part me jao
    //     return searchInBST(root->left, x);
    // }
    // else{
    //     // right part me jao
    //     return searchInBST(root->right, x);
    // }




    // Approach-2--> Itrative 
    BinaryTreeNode<int> * temp = root;

    while(temp != NULL)
    {
        if(temp->data == x)
        {
            return true;
        }
        if(temp->data > x)
        {
            temp = temp->left;
        }
        else{
            temp = temp->right;
        }
    }
    return false;
}