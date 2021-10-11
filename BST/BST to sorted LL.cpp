/*
Given a BST, convert it into a sorted linked list. Return the head of LL.
Input format :
Elements in level order form (separated by space)
(If any node does not have left or right child, take -1 in its place)
Output Format :
Linked list elements (separated by space)
Sample Input :
8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
Sample Output :
2 5 6 7 8 10
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

template<typename T>
class node{
    public:
    T data;
    node<T> *next;
    node(T data){
        this->data=data;
        this->next=NULL;
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


pair<node<int>*,node<int>*> constructBST(BinaryTreeNode<int> *root){
    if(root==NULL){
        pair<node<int>*,node<int>*> p;
        return p;
    }
    pair<node<int>*,node<int>*> pL=constructBST(root->left);
    pair<node<int>*,node<int>*> pR=constructBST(root->right);

    node<int> *temp=new node<int>(root->data);
    
    if(pL.first==NULL && pL.second==NULL){
        pair<node<int>*,node<int>*> pan=make_pair(temp,temp);
        return pan;
    }
    else{
        pL.second->next=temp;
        temp->next=pR.first;
    }
    pair<node<int>*,node<int>*> pans;
    pans.first=pL.first;
    pans.second=pR.second;
    return pans;

}

node<int> *sortedarray(BinaryTreeNode<int> *root){
    pair<node<int>*,node<int>*> p;
    p=constructBST(root);
    return p.first;
}

//8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
//4 2 6 1 3 5 7 -1 -1 -1 -1 -1 -1 -1 -1 
int main(){
    BinaryTreeNode<int> *root=takeInputLevelWise();
    node<int> *temp=sortedarray(root);
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    delete root;
} 



 
 
 
 
 
