/*
Given a binary tree, print that binary tree in vertical order. Vertical order is -
Print the nodes which are at same vertical order in same line separated by space. Print different levels in different lines.
Order of different levels in different lines is not important. But in one level, print the element in pre-order format.
Input Format :
Elements in level order form (separated by space). If any node does not have left or right child, take -1 in its place
Output Format :
Required output in given format
Sample Input :
1 2 3 4 5 6 7 -1 8 -1 -1 -1 -1 -1 -1 -1 -1
Sample Output :
7 
3 
4 
2 8 
1 5 6 
*/
#include<bits/stdc++.h>
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

void preord(BinaryTreeNode<int> *root,map<int,vector<int>> &m,int dis){
    if(root!=NULL){
        m[dis].push_back(root->data);
        preord(root->left,m,dis-1);
        preord(root->right,m,dis+1);
    }
}

void printBinaryTreeVerticalOrder(BinaryTreeNode<int> *root){
    map<int,vector<int>> m;
    
    preord(root,m,0);
    map<int,vector<int>>::iterator it;
    for(it=m.begin();it!=m.end();it++){
        vector<int> temp=it->second;

        for(int i=0;i<temp.size();i++){
            cout<<temp[i]<<" ";
        }
        cout<<endl;
    }

}

int main(){
    BinaryTreeNode<int> *root=takeInputLevelWise();
    printBinaryTreeVerticalOrder(root);
}
