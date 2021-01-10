// que : 1

#include <iostream>
using namespace std;
 
struct BSTNode
{
    int data;
    BSTNode* left;
    BSTNode* right; 
};
 
BSTNode* GetNewNode(int data)
{
    BSTNode* node=new BSTNode();
    node->data=data;
    node->left=NULL;
    node->right=NULL;
    return node;
}
 
BSTNode* insert(BSTNode* root,int data)
{
    if(root==NULL)
    {
        root=GetNewNode(data);
    }
    else if (data<=root->data)
    {
        root->left=insert(root->left,data);
    }
    else
    {
        root->right=insert(root->right,data);
    }
    return root;
    
}
 
void inorder(BSTNode* root)
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->left);
    cout<<root->data<<endl;
    inorder(root->right);
}
 
int main()
{
    BSTNode* root;
    root=NULL;        //empty binary tree
    root=insert(root,15);
    root=insert(root,10);
    root=insert(root,20);
    root=insert(root,25);
    root=insert(root,8);
    root=insert(root,12);
    cout<<"Data in tree in In-Order traversal is: "<<endl;
    inorder(root);
}
//  que :2
#include <iostream>
using namespace std;
 
struct BSTNode
{
    int data;
    BSTNode* left;
    BSTNode* right; 
};
 
BSTNode* GetNewNode(int data)
{
    BSTNode* node=new BSTNode();
    node->data=data;
    node->left=NULL;
    node->right=NULL;
    return node;
}
 
BSTNode* insert(BSTNode* root,int data)
{
    if(root==NULL)
    {
        root=GetNewNode(data);
    }
    else if (data<=root->data)
    {
        root->left=insert(root->left,data);
    }
    else
    {
        root->right=insert(root->right,data);
    }
    return root;
    
}
 
void inorder(BSTNode* root)
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->left);
    cout<<root->data<<endl;
    inorder(root->right);
}
 
BSTNode * minValueNode(BSTNode* node)
{
   BSTNode* newNode = node;
   while (newNode && newNode->left != NULL)
      newNode = newNode->left;
   return newNode;
}
 
BSTNode* deletion(BSTNode* root, int data)
{
    if(root==NULL)
    {
        return root;
    }
    else if(data<root->data)    root->left=deletion(root->left,data);
    else if(data>root->data)    root->right=deletion(root->right,data);
    else
    {
        if(root->left==NULL && root->right==NULL)
        {
            delete root;
            root=NULL;
            return root;
        }
        else if(root->left==NULL)
        {
            BSTNode* temp=root;
            root=root->right;
            delete temp;
        }
        else if(root->right==NULL)
        {
            BSTNode* temp=root;
            root=root->left;
            delete temp;
        }
        else
        {
            BSTNode* temp=minValueNode(root->right);
            root->data=temp->data;
            root->right=deletion(root->right,temp->data);
        }
    }
    return root;
}
 
int main()
{
    BSTNode* root;
    root=NULL;        //empty binary tree
    root=insert(root,15);
    root=insert(root,10);
    root=insert(root,20);
    root=insert(root,25);
    root=insert(root,8);
    root=insert(root,12);
    cout<<"Data in tree in In-Order traversal is: "<<endl;
    inorder(root);
 
    deletion(root,8);
    cout<<"Data in tree after deleting left child node: "<<endl;
    inorder(root);
 
    deletion(root,20);
    cout<<"Data in tree after deleting right child node:  "<<endl;
    inorder(root);
}
