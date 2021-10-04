/*
Given Postorder and Inorder traversal of a binary tree, create the binary tree associated with the traversals.You just need to construct the tree and return the root.
Note: Assume binary tree contains only unique elements.
Input format :
Line 1 : n (Total number of nodes in binary tree)
Line 2 : Post order traversal
Line 3 : Inorder Traversal
Output Format :
Elements are printed level wise, each level in new line (separated by space).
Sample Input :
8
8 4 5 2 6 7 3 1
4 8 2 5 1 6 3 7
Sample Output :
1 
2 3 
4 5 6 7 
8
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


void printTreeLevelWise(BinaryTreeNode<int> *root){
    if(root==NULL)
        return;
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    q.push(NULL);
    while(q.size()!=0){
        BinaryTreeNode<int> *first=q.front();
        q.pop();
        if(first == NULL) {
				if(q.empty()) {
					break;
				}
				cout << endl;
				q.push(NULL);
				continue;
			}
			cout << first -> data << " ";
			if(first -> left != NULL) {
				q.push(first -> left);
			}
			if(first -> right != NULL) {
				q.push(first -> right);
			}
    }

}


BinaryTreeNode<int> *buildTreeHelper(int *in,int *post,int inS,int inE,int postS,int postE){
    if(inS > inE){
        return NULL;
    }
    int rootData=post[postE];
    int rootIndex=-1;
    for(int i=inS;i<=inE;i++){
        if(in[i]==rootData){
            rootIndex=i;
            break;
        }
    }
    int lInS=inS;
    int lInE=rootIndex-1;
    int lPostS=postS;
    int lPostE=lInE-lInS+lPostS;
    int rInS=rootIndex+1;
    int rInE=inE;
    int rPostS=lPostE+1;
    int rPostE=rInE-rInS+rPostS;
    BinaryTreeNode<int> *root=new BinaryTreeNode<int>(rootData);
    root->left=buildTreeHelper(in,post,lInS,lInE,lPostS,lPostE);
    root->right=buildTreeHelper(in,post,rInS,rInE,rPostS,rPostE);
    return root;
}

BinaryTreeNode<int> *buildTree(int *in,int *post,int size){
    return buildTreeHelper(in,post,0,size-1,0,size-1);
}
 
int main(){
    int size;
    cin>>size;
    int *in=new int[size];
    int *post=new int[size];
    for(int i=0;i<size;i++)
        cin>>post[i];
    for(int i=0;i<size;i++)
        cin>>in[i];
    BinaryTreeNode<int> *root=buildTree(in,post,size);
    printTreeLevelWise(root);
    delete root;
} 
 
 
