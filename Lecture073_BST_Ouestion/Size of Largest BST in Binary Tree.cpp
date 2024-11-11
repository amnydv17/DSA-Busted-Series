// Itrative Approach Approach
// TC---> O(n)
// SC---> O(n)


// class Solution{
//     public:
 
//     vector<int> solve(TreeNode * root){
//         //{//size,TF,mini,maxi} left max<node<right min
//         if(root == NULL){//null
//             return {0,1,INT_MAX,INT_MIN};
//         }
//         {
//             if(root->left==NULL && root->right==NULL){//leaf
//                 return {1,1,root->data,root->data};
//             }
//             vector<int>left=solve(root->left);
//             vector<int>right=solve(root->right);
            
//             int leftsize=left[0],LTF=left[1],leftmini=left[2],leftmaxi=left[3];
//             int rightsize=right[0],RTF=right[1],rightmini=right[2],rightmaxi=right[3];
//             if(LTF ==1 && RTF==1 && root->data>leftmaxi && root->data<rightmini){
//                 return {leftsize+rightsize+1,1,min(root->data,leftmini),max(root->data,rightmaxi)};
//             }
//             else{
//                 return {max(leftsize,rightsize),0,0,0};
//             }
//         }
//     }
    
//     int largestBst(TreeNode * root)
//     {
//     	//Aman Yadav
//     	return solve(root)[0];
//     }
// };












// Recursive Approach
// TC---> O(n)
// SC---> O(n)



class info{
    public:
        int maxi;
        int mini;
        int size;
        bool isBST;
};

info solve(TreeNode * root, int&ans)
{
    // base case
    if(root == NULL)
    {
        return {INT_MIN, INT_MAX, 0, true};
    }

    // recursive call for left and right
    info left = solve(root->left, ans);
    info right = solve(root->right, ans);
    
    info currNode; // curr node 
    // updation of curr node
    currNode.maxi = max(root->data, right.maxi);
    currNode.mini = min(root->data, left.mini);
    currNode.size = left.size + right.size + 1;
    
    // check to curr node is valid bst or not
    
    if(left.isBST && right.isBST && (root->data > left.maxi && root->data < right.mini))
    {
        currNode.isBST = true;
    }
    else{
        currNode.isBST = false;
    }
    
    // Answer Update
    if(currNode.isBST)
    {
        ans = max(ans, currNode.size);
    }
    
    return currNode;
}
int largestBST(TreeNode * root){
    
    	//Aman Yadav
    	int maxSize = 0;
    	info result = solve(root, maxSize);
    	return maxSize;
}