// Time Complexity = O(n)--> traversing whole inorder array
// Space Complexity = O(n)--> storing inorder

void inorder(BinaryTreeNode<int>* root, vector<int> &ans)
{
    if(root == NULL)
    return ;

    inorder(root->left, ans);
    ans.push_back(root->data);
    inorder(root->right, ans);
}

bool twoSumInBST(BinaryTreeNode<int>* root, int target) {
	//Aman Yadav
    vector<int>inorderVal;
    // store inorder ---> sorted
    inorder(root, inorderVal);

    int i = 0;
    int j = inorderVal.size()-1;

    while(i<j)
    {
        int sum = inorderVal[i] + inorderVal[j];
        if(sum == target)
        return true;

        else if(sum > target)
            j--;

        else
            i++;
    }
return false;
}