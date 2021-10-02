/*
Mirror the given binary tree. That is, right child of every nodes should become left and left should become right.
Alt text
Note : You don't need to print or return the tree, just mirror it.
Input format :
Line 1 : Elements in level order form (separated by space)
(If any node does not have left or right child, take -1 in its place)
Output format : Elements in level order form (Every level in new line)
Sample Input 1:
1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
Sample Output 1:
1 
3 2 
7 6 5 4
Sample Input 2:
5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1
Sample Output 2:
5 
6 10 
3 2 
9
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

void mirrorBinaryTree(BinaryTreeNode<int> *root){
    if(root==NULL)
        return;
    BinaryTreeNode<int> *temp=root->left;
    root->left=root->right;
    root->right=temp;

    mirrorBinaryTree(root->left);
    mirrorBinaryTree(root->right);
}

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
    mirrorBinaryTree(root);
    printTreeLevelWise(root);
    delete root;
} 
 
 
 
