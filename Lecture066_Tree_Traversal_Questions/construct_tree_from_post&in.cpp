class Solution {
  public:
    void createMapping(int in[], map<int, int>&nodeToIndex, int n){
        for(int i=0; i<n; i++){  
            nodeToIndex[in[i]] = i;
        }
    }
    
    Node * solve(int in[], int post[], int &index, int inorderStart, 
                    int inorderEnd, int n, map<int, int>&nodeToIndex)
    {
        // base case
        if(index < 0 || inorderStart > inorderEnd){
            return NULL;
        }
        
        // create a root node for element
        int ele = post[index--];
        Node *root = new Node(ele);

        // find element index in inorder
        int position = nodeToIndex[ele];
        
        // recursive calls
        root->right = solve(in, post, index,position + 1, inorderEnd,n, nodeToIndex);
        root->left = solve(in, post, index,inorderStart, position-1,n, nodeToIndex);
        
        return root;
    
    }

    // Function to return a tree created from postorder and inoreder traversals.
    Node *buildTree(int n, int in[], int post[]) {
        int postOrderIndex = n-1;
        map<int, int>nodeToIndex;
        // create nodes to index mapping
        createMapping(in,nodeToIndex, n);
        
        Node* ans = solve(in, post, postOrderIndex,0, n-1,n,  nodeToIndex);
        return ans;
    }
};