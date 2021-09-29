/*
Given a binary tree, find and return the min and max data value of given binary tree.
Return the output as an object of PairAns class, which is already created.
Input format :
Elements in level order form (separated by space)
(If any node does not have left or right child, take -1 in its place)
Output Format :
Max and min (separated by space)
Sample Input :
8 3 10 1 6 -1 14 -1 -1 4 7 13 -1 -1 -1 -1 -1 -1 -1
Sample Output :
14 1
*/
#include<iostream>
#include<queue>
#include<climits>
using namespace std;

template<typename T>
class BinaryTreeNode{
    public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;
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

class PairAns{
    public:
    int min,max;
};

BinaryTreeNode<int> *takeInputLevelwise(){
    int rootData;
    cin>>rootData;
    if(rootData==-01)
        return NULL;
    BinaryTreeNode<int> *root=new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size()!=0){
        BinaryTreeNode<int> *front=pendingNodes.front();
        pendingNodes.pop();
        int leftchild,rightchild;
        cin>>leftchild;
        if(leftchild!=-1){
            BinaryTreeNode<int> *child=new BinaryTreeNode<int>(leftchild);
            front->left=child;
            pendingNodes.push(child);
        }
        cin>>rightchild;
        if(rightchild!=-1){
            BinaryTreeNode<int> *child=new BinaryTreeNode<int>(rightchild);
            front->right=child;
            pendingNodes.push(child);
        }
    }
    return root;
}

void trav(BinaryTreeNode<int> *root,int &minx,int &maxx){
    if(root==NULL)
        return;
    minx=min(minx,root->data);
    maxx=max(maxx,root->data);

    trav(root->left,minx,maxx);
    trav(root->right,minx,maxx);
}

PairAns MinMax(BinaryTreeNode<int> *root){
    int minx=INT_MAX;
    int maxx=INT_MIN;

    trav(root,minx,maxx);
    PairAns p;
    p.min=minx;
    p.max=maxx;
    return p;
}
int main(){
    BinaryTreeNode<int> *root=takeInputLevelwise();
    PairAns ans=MinMax(root);
    cout<<ans.max<<" "<<ans.min<<endl;
}

