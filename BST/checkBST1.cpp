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

BinaryTreeNode<int> *takeinput(){
    int rootdata;
    cout<<"Enter data"<<endl;
    cin>>rootdata;
    if(rootdata==-1){
        return NULL;
    }
    BinaryTreeNode<int> *root=new BinaryTreeNode<int>(rootdata);
    BinaryTreeNode<int> *leftchild=takeinput();
    BinaryTreeNode<int> *rightchild=takeinput();
    root->left=leftchild;
    root->right=rightchild;
    return root;
}

int numNodes(BinaryTreeNode<int> *root){
    if(root==NULL){
        return 0;
    }
    return 1+numNodes(root->left)+numNodes(root->right);
}

BinaryTreeNode<int> *findnode(BinaryTreeNode<int> *root,int k){
    if(root==NULL)
        return NULL;
    if(root->data==k)
        return root;
    if(root->data>k)
        return findnode(root->left,k);
    else
        return findnode(root->right,k);
    
}

void printbetweenk1k2(BinaryTreeNode<int> *root,int k1,int k2){
    if(root==NULL)
        return;
    if(root->data>=k1 && root->data<=k2){
        cout<<root->data<<endl;
    }
    if(root->data>k1){
        printbetweenk1k2(root->left,k1,k2);
    }
    if(root->data<=k2){
        printbetweenk1k2(root->right,k1,k2);
    }
}

int maximum(BinaryTreeNode<int> *root){
    if(root==NULL)
        return INT_MIN;
    return max(root->data,max(maximum(root->left),maximum(root->right)));
}

int minimum(BinaryTreeNode<int> *root){
    if(root==NULL)
        return INT_MAX;
    return min(root->data,min(minimum(root->left),minimum(root->right)));
}

bool isBST(BinaryTreeNode<int> *root){
    if(root==NULL)
        return true;
    int leftmax=maximum(root->left);
    int rightmin=minimum(root->right);
    bool output=(root->data>leftmax) && (root->data<rightmin)&& isBST(root->left) && isBST(root->right);
    return output;
}

//8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
int main(){
    BinaryTreeNode<int> *root=takeInputLevelWise();
    cout<<isBST(root)<<endl;
    delete root;
} 



 
 
