/*
Given a binary tree, return the longest path from leaf to root. Longest means, a path which contain maximum number of nodes from leaf to root.
Input format :
Elements in level order form (separated by space)
(If any node does not have left or right child, take -1 in its place)
Line 1 : Binary Tree 1 (separated by space)
Sample Input 1 :
 5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1
Sample Output 1 :
9
3
6
5
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

void help(BinaryTreeNode<int>* root,vector <int> &v,vector<int> &ans){
    
    if(root==NULL){
        if(v.size()>ans.size())
            ans=v;
        return;
    }
    v.push_back(root->data);
    help(root->left,v,ans);
    help(root->right,v,ans);
    v.pop_back();
}

vector<int> *longpath(BinaryTreeNode<int> *root){
    vector<int> v;
    vector<int> ans;

    help(root,v,ans);
    vector <int>* p=new vector<int>; //Take a note of this
    for(int i=ans.size()-1;i>=0;i--)
    {
        int k=ans[i];
        p->push_back(k);
    }
    return p;
}

int main(){
    BinaryTreeNode<int> *root=takeInputLevelWise();
    vector<int> ans=longpath(root);
    for(i=0;i<ans.size();i++)
        cout<<ans[i]<<endl;
    delete root;
}