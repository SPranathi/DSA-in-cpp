/*Code: Construct BST from a Sorted Array
Given a sorted integer array A of size n which contains all unique elements. You need to construct a balanced BST from this input array. Return the root of constructed BST.Note : If array size is even, take first mid as root.
Sample Input :
7
1 2 3 4 5 6 7
Sample Output :
4 2 1 3 6 5 7
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

void printTree(BinaryTreeNode<int> *root){
    if(root==NULL)
        return;
    if(root->left!=NULL){
        cout<<root->left->data<<" ";
        printTree(root->left);
    }
    if(root->right!=NULL){
        cout<<root->right->data<<" ";
        printTree(root->right);

    }
}

BinaryTreeNode<int> *tree(int *input, int si, int ei){
    if(si > ei){    //base case
        return NULL;
    }
    int mid = (si+ ei) / 2;    //mid of array
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(input[mid]);    //assign mid as root
    root -> left = tree(input, si, mid - 1);    // call to left
    root -> right = tree(input, mid + 1, ei);    // call to right
    return root;
}

//8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
//4 2 6 1 3 5 7 -1 -1 -1 -1 -1 -1 -1 -1 
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    BinaryTreeNode<int> *root=tree(arr,0,n-1);
    cout<<root->data<<" ";
    printTree(root);
    delete root;
} 



 
 
 
 
 
