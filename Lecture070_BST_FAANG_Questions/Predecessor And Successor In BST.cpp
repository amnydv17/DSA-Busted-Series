pair<int, int> predecessorSuccessor(TreeNode *root, int key)
{
    TreeNode *temp = root;
    int pred = -1;
    int succ = -1;

    // Step 1: Find the key node while updating potential predecessor and successor
    while (temp && temp->data != key)
    {
        if (temp->data > key)
        {
            succ = temp->data;  // Possible successor
            temp = temp->left;
        }
        else
        {
            pred = temp->data;  // Possible predecessor
            temp = temp->right;
        }
    }

    // If the key node is not found
    if (!temp) return {pred, succ};

    // Step 2: Find predecessor in the left subtree
    if (temp->left)
    {
        TreeNode *leftTree = temp->left;
        while (leftTree->right)
        {
            leftTree = leftTree->right;
        }
        pred = leftTree->data;
    }

    // Step 3: Find successor in the right subtree
    if (temp->right)
    {
        TreeNode *rightTree = temp->right;
        while (rightTree->left)
        {
            rightTree = rightTree->left;
        }
        succ = rightTree->data;
    }

    return {pred, succ};
}