/*
Given a BST and an integer K, you need to find the Kth smallest element present in the BST. Return INT_MIN if that is not present in the BST.
Input format :
Line 1: Elements in level order form (separated by space)
(If any node does not have left or right child, take -1 in its place)
Output Format:
Line 1: Kth smallest node
Sample Input :
8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
3
Sample Output :
6
 */

#include<iostream>
#include<queue>
#include<climits>
using namespace std;

template<typename T>
class BinaryTreeNode{
    public:
    T data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;

    BinaryTreeNode(T data){
        this->data=data;
        left=NULL;
        right=NULL;
    }

    ~BinaryTreeNode(){
        delete left;
        delete right;
    }
};

BinaryTreeNode<int> *takeInputLevelWise(){
    int rootdata;
    //cout<<"Enter root data"<<endl;
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
        //cout<<"Enter left child of "<<front->data<<endl;
        int leftchilddata;
        cin>>leftchilddata;
        if(leftchilddata!=-1){
            BinaryTreeNode<int> *child=new BinaryTreeNode<int>(leftchilddata);
            front->left=child;
            pendingNodes.push(child);
        }
        //cout<<"Enter right child of "<<front->data<<endl;
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

void inorder(BinaryTreeNode<int> *root,vector<int> &v){
    if(root==NULL)
        return ;
    inorder(root->left,v);
    v.push_back(root->data);
    inorder(root->right,v);
}

int findnode(BinaryTreeNode<int> *root,int k){
    vector<int> v;
    inorder(root,v);
    if(k>v.size())
        return INT_MIN;
    else
        return v[k-1];
}
int main(){
    BinaryTreeNode<int> *root=takeInputLevelWise();
    int k;
    cin>>k;
    cout<<findnode(root,k)<<endl;
    delete root;
}