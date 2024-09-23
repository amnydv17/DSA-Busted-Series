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

int main(){
  Node* root = NULL;
  cout<<"Enter data to Create BST" <<endl;
  takeInput(root);
  cout<<"printing LevelOrder BST"<<endl;
  levelOrderTraversal(root);

  cout << "inorder traversal is:  ";
  inorder(root); 

  cout << endl << "preorder traversal is:  ";
  preorder(root); 

  cout << endl << "postorder traversal is:  ";
  postorder(root);

 return 0;
}