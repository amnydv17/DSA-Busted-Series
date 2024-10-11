class Solution{
    void createMapping(int in[], map<int, int>&nodeToIndex, int n){
        for(int i=0; i<n; i++){  // O(1)
            nodeToIndex[in[i]] = i;
        }
    }
    
    Node * solve(int in[], int pre[], int &index, int inorderStart, 
    int inorderEnd, int n, map<int, int>&nodeToIndex)
    {
        // base case
        if(index>=n || inorderStart > inorderEnd){
            return NULL;
        }
        

        // create a root node for element
        int ele = pre[index++];
        Node *root = new Node(ele);

        // find element index in inorder
        int position = nodeToIndex[ele];
        
        // recursive calls
        root->left = solve(in, pre, index,inorderStart, position-1,n, nodeToIndex);
        root->right = solve(in, pre, index,position + 1, inorderEnd,n, nodeToIndex);
        
        return root;
    
    }
    public:
    Node* buildTree(int in[],int pre[], int n)
    {
        int preOrderIndex = 0;
        map<int, int>nodeToIndex;
        // create nodes to index mapping
        createMapping(in,nodeToIndex, n);
        
        Node* ans = solve(in, pre, preOrderIndex,0, n-1,n,  nodeToIndex);
        return ans;
}