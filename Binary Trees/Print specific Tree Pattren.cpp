/*
Given a "complete" binary tree , print the following pattern using its all nodes.
root element
first element of second level
last element of  of second level
first element of the of the third level
last element of the third level
second element of the third level
second from last element of the third level
..... So on.
Example :
For tree :
Alt text
The pattern should be: 
1 2 3 4 7 5 6 8 15 9 14 10 13 11 12
Input Format
Line 1: Nodes in level order form (separated by space). If any node does not have left or right child, take -1 in its place
Output Format
Required pattern
Constraint
Given binary tree is complete
1 <= Number of Nodes <= 10^6
1 <= value of each node <= 10^8
Sample Input 1
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
Sample Output 1
1 2 3 4 7 5 6 8 15 9 14 10 13 11 12
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

void PrintSpecificPattern(BinaryTreeNode<int> *root){
    vector<int> v;
    levels(root,v);
}

int main(){
    BinaryTreeNode<int> *root=takeInputLevelWise();
    PrintSpecificPattern(root);
}