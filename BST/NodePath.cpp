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

vector<int> *getRootToNodePath(BinaryTreeNode<int> *root,int data){
    if(root==NULL)
        return NULL;
    if(root->data==data){
        vector<int> *output=new vector<int>();
        output->push_back(root->data);
        return output;
    }
    vector<int> *leftoutput=getRootToNodePath(root->left,data);
    if(leftoutput!=NULL){
        leftoutput->push_back(root->data);
        return leftoutput;
    }
    vector<int> *rightoutput=getRootToNodePath(root->right,data);
    if(rightoutput!=NULL){
        rightoutput->push_back(root->data);
        return rightoutput;
    }
    else{
        return NULL;
    }
}

//8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
//4 2 6 1 3 5 7 -1 -1 -1 -1 -1 -1 -1 -1 
int main(){
    int data;
    BinaryTreeNode<int> *root=takeInputLevelWise();
    cin>>data;
    vector<int> *output=getRootToNodePath(root,data);
    for(int i=0;i<output->size();i++){
        cout<<output->at(i)<<endl;
    }
    delete output;
    delete root;
} 



 
 
 
 
 
