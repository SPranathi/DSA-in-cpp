#include<iostream>
#include "BinaryTreeNode.h"
#include<queue>
using namespace std;

BinaryTreeNode<int> *takeInputLevelWise(){
    int rootdata;
    cout<<"Enter root data"<<endl;
    cin>>rootdata;
    if(rootdata==-1){
        return NULL;
    }
    BinaryTreeNode<int> *root=new BinaryTreeNode<int>(rootdata);

    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size()!=0){
        BinaryTreeNode<int> *front=pendingNodes.front();
        pendingNodes.pop();
        cout<<"Enter left child of "<<front->data<<endl;
        int leftchilddata;
        cin>>leftchilddata;
        if(leftchilddata!=-1){
            BinaryTreeNode<int> *child=new BinaryTreeNode<int>(leftchilddata);
            front->left=child;
            pendingNodes.push(child);
        }
        cout<<"Enter right child of "<<front->data<<endl;
        int rightchilddata;
        cin>>rightchilddata;
        if(rightchilddata!=-1){
            BinaryTreeNode<int> *child=new BinaryTreeNode<int>(rightchilddata);
            front->right=child;
            pendingNodes.push(child);
        }
    }
    return root;
}
void printTree(BinaryTreeNode<int> *root){
    if(root==NULL)
        return;
    cout<<root->data<<":";
    if(root->left!=NULL){
        cout<<"L"<<root->left->data;
    }
    if(root->right!=NULL){
        cout<<"R"<<root->right->data;
    }
    cout<<endl;
    printTree(root->left);
    printTree(root->right);

}

BinaryTreeNode<int> *takeinput(){
    int rootdata;
    cout<<"Enter data"<<endl;
    cin>>rootdata;
    if(rootdata==-1){
        return NULL;
    }
    BinaryTreeNode<int> *root=new BinaryTreeNode<int>(rootdata);
    BinaryTreeNode<int> *leftchild=takeinput();
    BinaryTreeNode<int> *rightchild=takeinput();
    root->left=leftchild;
    root->right=rightchild;
    return root;
}

int numNodes(BinaryTreeNode<int> *root){
    if(root==NULL){
        return 0;
    }
    return 1+numNodes(root->left)+numNodes(root->right);
}

void inorder(BinaryTreeNode<int> *root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}


//1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1 
int main(){
    /*BinaryTreeNode<int> *root=new BinaryTreeNode<int>(1);
    BinaryTreeNode<int> *node1=new BinaryTreeNode<int>(2);
    BinaryTreeNode<int> *node2=new BinaryTreeNode<int>(3);
    root->left=node1;
    root->right=node2;*/
    BinaryTreeNode<int> *root=takeInputLevelWise();
    printTree(root);
    cout<<"Num: "<<numNodes(root)<<endl;
    inorder(root);
    delete root;
} 
