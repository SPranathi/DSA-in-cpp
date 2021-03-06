/*
Given Preorder and Inorder traversal of a binary tree, create the binary tree associated with the traversals.You just need to construct the tree and return the root.
Note: Assume binary tree contains only unique elements.
Input format :
Line 1 : n (Total number of nodes in binary tree)
Line 2 : Pre order traversal
Line 3 : Inorder Traversal
Output Format :
Elements are printed level wise, each level in new line (separated by space).
Sample Input :
12
1 2 3 4 15 5 6 7 8 10 9 12
4 15 3 2 5 1 6 10 8 7 9 12
Sample Output :
1 
2 6 
3 5 7 
4 8 9 
15 10 12
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


BinaryTreeNode<int> *buildTreeHelper(int *in,int *pre,int inS,int inE,int preS,int preE){
    if(inS > inE){
        return NULL;
    }
    int rootData=pre[preS];
    int rootIndex=-1;
    for(int i=inS;i<=inE;i++){
        if(in[i]==rootData){
            rootIndex=i;
            break;
        }
    }
    int lInS=inS;
    int lInE=rootIndex-1;
    int lPreS=preS+1;
    int lPreE=lInE-lInS+lPreS;
    int rInS=rootIndex+1;
    int rInE=inE;
    int rPreS=lPreE+1;
    int rPreE=preE;
    BinaryTreeNode<int> *root=new BinaryTreeNode<int>(rootData);
    root->left=buildTreeHelper(in,pre,lInS,lInE,lPreS,lPreE);
    root->right=buildTreeHelper(in,pre,rInS,rInE,rPreS,rPreE);
    return root;
}

BinaryTreeNode<int> *buildTree(int *in,int *pre,int size){
    return buildTreeHelper(in,pre,0,size-1,0,size-1);
}
 
int main(){
    int size;
    cin>>size;
    int *in=new int[size];
    int *pre=new int[size];
    for(int i=0;i<size;i++)
        cin>>pre[i];
    for(int i=0;i<size;i++)
        cin>>in[i];
    BinaryTreeNode<int> *root=buildTree(in,pre,size);
    printTreeLevelWise(root);
    delete root;
} 
 
