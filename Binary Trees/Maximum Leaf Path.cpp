/*
Given a binary tree of N nodes, find and return the maximum sum path between two leaves of the given tree.
Given binary tree contains positive values only.
Input format :
Line 1 : Nodes in level order form (separated by space). If any node does not have left or right child, take -1 in its place
Output format :
Maximum sum path
Constraints :
1 <= N <= 10^5
Sample Input :
10 9 4 3 1 5 8 -1 -1 -1 -1 -1 6 -1 -1 3 -1 -1 -1
Sample Output :
40
*/


#include<iostream>
#include<queue>
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

long long int lsum(BinaryTreeNode<int> *root){
    if(root==NULL)
        return 0 ;
    return root->data+max(lsum(root->left),lsum(root->right));
}

void trav(BinaryTreeNode<int> *root,long long int &msum){
    if(root==NULL)
        return;
    long long ans=root->data+lsum(root->left)+lsum(root->right);
    msum=max(msum,ans);

    trav(root->left,msum);
    trav(root->right,msum);
}

long long int maximumleafsum(BinaryTreeNode<int> *root){
    long long int msum=0;
    trav(root,msum);
    return msum;
}

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


int main(){
    BinaryTreeNode<int> *root=takeInputLevelWise();
    cout<<maximumleafsum(root)<<endl;
    delete root;
} 
