#include<iostream>
using namespace std;
struct Node
{
	int data;
    Node* left;
    Node* right;
};
Node* GetNewNode(int data)
{
	Node* newNode = new Node();
	newNode->data = data;
    newNode->left = newNode->right = NULL;

    return newNode;

}

Node* Insert(Node* root,int data)
{
	if(root == NULL)
    {
	    root = GetNewNode(data);
    }
    else if(data <= root->data)
    {
       root->left = Insert(root->left,data);
    }
    else
	{
       root->right = Insert(root->right,data);
    }
    return root;
}
bool Search(Node* root,int data)
{
    if(root == NULL)
	{
      return false;
    }
    else if(root->data == data)
    {
      return true;
    }
    else if(data <= root->data)
    {
      return Search(root->left,data);
    }
    else
	{
      return Search(root->right,data);
    }
}

void Inorder(Node *root)
{
	if(root == NULL) return;
    Inorder(root->left);
    cout <<root->data << " ";
    Inorder(root->right);

}

void Preorder(struct Node* root)
{
   if (root == NULL)
       return;
   cout << root->data << " ";
   Preorder(root->left);
   Preorder(root->right);
}


 void Postorder(struct Node* root)
{
	if (root == NULL)
    return;
    Postorder(root->left);
    Postorder(root->right);
    cout << root->data << " ";
}

int maxDepthbst(Node* root)
{
    if (root == NULL)
        return 0;
    else
    {
        int lDepth = maxDepthbst(root->left);
        int rDepth = maxDepthbst(root->right);

        if (lDepth > rDepth)
            return(lDepth + 1);
        else return(rDepth + 1);
    }
}
int count(struct Node* root)
{
	if (root==NULL)
	{
		return 0;
	}
	else
	{
		int num=(1+count(root->left)+count(root->right));
		return num;
	}
}
Node* FindMin(Node* root)
{
    while(root->left != NULL)
	root = root->left;
    return root;
}
struct Node* Delete(struct Node *root, int data)
{
   if(root == NULL)
      return root;
   else if(data < root->data)
      root->left = Delete(root->left,data);
   else if (data > root->data)
      root->right = Delete(root->right,data);
   else
   {
      if(root->left == NULL && root->right == NULL)
        {
           delete root;
           root = NULL;
        }
       else if(root->left == NULL)
        {
          struct Node *temp = root;
          root = root->right;
          delete temp;
        }
        else if(root->right == NULL)
        {
          struct Node *temp = root;
          root = root->left;
          delete temp;
        }
   else
   {
        struct Node *temp = FindMin(root->right);
        root->data = temp->data;
        root->right = Delete(root->right,temp->data);
   }
   }
   return root;
}

int main()
{
	Node* root = NULL;
    root = Insert(root,15);
    root = Insert(root,10);
    root = Insert(root,20);
    root = Insert(root,25);
    root = Insert(root,8);
    root = Insert(root,12);

    int number;
    cout<<"Enter number be searched\n";
    cin>>number;
    if(Search(root,number) == true) cout<<"Found\n";
    else cout<<"Not Found\n";
    root = Delete(root,15);
    cout<<"Enter number be searched\n";
    cin>>number;
    if(Search(root,number) == true) cout<<"Found\n";
    else cout<<"Not Found\n";
    cout << "\nInorder traversal of binary tree is \n";
    Inorder(root);
    cout << "\nPreorder traversal of binary tree is \n";
    Preorder(root);
    cout << "\nPostorder traversal of binary tree is \n";
    Postorder(root);
    cout << "\nHeight of tree is \n" << maxDepthbst(root);
    cout<<"\nCount of the node is \n"<<count(root);
    return 0;
}
