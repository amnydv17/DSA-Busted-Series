#include<iostream>
using namespace std;
#include<queue>

class Node {

  public:
    int data;
    Node* left;
    Node* right;

    Node(int d)
    {
      this->data = d;
      this->left = NULL;
      this->right = NULL;
    }
};

<<<<<<< HEAD

// Traversal In BST
=======
>>>>>>> 2ec475d7dfbe176acaafb32c8be04b1daf5ba628
void inorder(Node* root) {
    //base case
    if(root == NULL) {
        return ;
    }

    inorder(root->left);
    cout << root-> data << " ";
    inorder(root->right);

}

void preorder(Node* root) {
    //base case
    if(root == NULL) {
        return ;
    }

    cout << root-> data << " ";
    preorder(root->left);
    preorder(root->right);

}

void postorder(Node* root) {
    //base case
    if(root == NULL) {
        return ;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root-> data << " ";

}

void levelOrderTraversal(Node* root) {
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if(temp == NULL) { 
            //purana level complete traverse ho chuka hai
            cout << endl;
            if(!q.empty()) { 
                //queue still has some child ndoes
                q.push(NULL);
            }  
        }
        else{
            cout << temp -> data << " ";
            if(temp ->left) {
                q.push(temp ->left);
            }

            if(temp ->right) {
                q.push(temp ->right);
            }
        }
    }

}


<<<<<<< HEAD
// Insertion in BST

=======
>>>>>>> 2ec475d7dfbe176acaafb32c8be04b1daf5ba628
Node* insertIntoBST(Node* root, int d)
{
  // base case
  if(root == NULL)
  {
    root = new Node(d);
    return root;
  }

  if(d > root -> data)
  {
    // right part me insert karna
    root->right = insertIntoBST(root->right, d);
  }

  else{
    // left part me insert karna
    root->left = insertIntoBST(root->left, d);
  }

  return root;
}

void takeInput(Node* &root){
  int data;
  cin>>data;

  while(data != -1)
  {
    root = insertIntoBST(root, data);
    cin>>data;
  }
}

<<<<<<< HEAD
Node* minVal(Node* root)
{
  Node* temp = root;

  while(temp->left != NULL)
  {
    temp = temp->left;
  }
  return temp;
}

Node* maxVal(Node* root)
{
  Node* temp = root;

  while(temp->right != NULL)
  {
    temp = temp->right;
  }
  return temp;
}

// Deletation in BST
Node* deleteInBST(Node* root, int val)
{
  if(root == NULL)
  return root;

  if(root->data == val)
  {
    // 0 child
    if(root->left == NULL && root->right == NULL)
    {
      delete root;
      return NULL;
    }

    // 1 child

    // left child
    if(root->left != NULL && root->right == NULL)
    { 
      Node* temp = root->left;
      delete root;
      return temp;
    }

    // right child
    if(root->left == NULL && root->right != NULL)
    { 
      Node* temp = root->right;
      delete root;
      return temp;
    }

    // 2 child
    // copy max value of root->left
    if(root->left != NULL && root->right != NULL)
    { 
      int maxi = maxVal(root->left)->data;
      root->data = maxi;
      root->left = deleteInBST(root->left, maxi);
      return root;
    }
  }

  else if(root->data > val)
  {
    // left part me jao
    root->left = deleteInBST(root->left, val);
    return root;
  }

  else
  {
    // right part me jao
    root->right = deleteInBST(root->right, val);
    return root;
  }
}


=======
>>>>>>> 2ec475d7dfbe176acaafb32c8be04b1daf5ba628
int main(){
  Node* root = NULL;
  cout<<"Enter data to Create BST" <<endl;
  takeInput(root);
<<<<<<< HEAD


=======
>>>>>>> 2ec475d7dfbe176acaafb32c8be04b1daf5ba628
  cout<<"printing LevelOrder BST"<<endl;
  levelOrderTraversal(root);

  cout << "inorder traversal is:  ";
  inorder(root); 

  cout << endl << "preorder traversal is:  ";
  preorder(root); 

  cout << endl << "postorder traversal is:  ";
  postorder(root);

<<<<<<< HEAD
  cout<<endl<<"Min Value of BST is-->"<<minVal(root) -> data <<endl;

  cout<<"Max Value of BST is-->"<<maxVal(root) -> data <<endl;


  // deletion
  root = deleteInBST(root, 50);

  cout<<endl<<endl<<"After Deletion"<<endl;

  cout<<"printing LevelOrder BST"<<endl;
  levelOrderTraversal(root);

  cout << "inorder traversal is:  ";
  inorder(root); 

  cout << endl << "preorder traversal is:  ";
  preorder(root); 

  cout << endl << "postorder traversal is:  ";
  postorder(root);

  cout<<endl<<"Min Value of BST is-->"<<minVal(root) -> data <<endl;

  cout<<"Max Value of BST is-->"<<maxVal(root) -> data <<endl;


=======
>>>>>>> 2ec475d7dfbe176acaafb32c8be04b1daf5ba628
 return 0;
}