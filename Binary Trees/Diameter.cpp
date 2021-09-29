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

BinaryTreeNode<int> *takeInputlevelwise(){
    int rootdata;
    cin>>rootdata;
    if(rootdata==-1)
        return NULL;
    BinaryTreeNode<int> *root=new BinaryTreeNode<int>(rootdata);

    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size()!=0){
        BinaryTreeNode<int> *front=pendingNodes.front();
        pendingNodes.pop();
        cout<<"Enter left child of "<<front->data<<endl;
        int leftchildData;
        cin>>leftchildData;
        if(leftchildData!=-1){
            BinaryTreeNode<int> *child=new BinaryTreeNode<int>(leftchildData);
            front->left=child;
            pendingNodes.push(child);
        }
        cout<<"Enter right child of "<<front->data<<endl;
        int rightchildData;
        cin>>rightchildData;
        if(rightchildData!=-1){
            BinaryTreeNode<int> *child=new BinaryTreeNode<int>(rightchildData);
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
    if(root->left!=NULL)
        cout<<"L"<<root->left->data;
    if(root->right!=NULL)
        cout<<"R"<<root->right->data;
    cout<<endl;
    printTree(root->left);
    printTree(root->right);
}

int height(BinaryTreeNode<int> *root){
    if(root==NULL)
        return 0;
    return 1+max(height(root->left),height(root->right));
}
int diameter(BinaryTreeNode<int> *root){
    if(root==NULL)
        return 0;
    int option1=height(root->left)+height(root->right);
    int option2=diameter(root->left);
    int option3=diameter(root->right);
    return std::max(option1,max(option2,option3));
}

pair<int,int> heightDiameter(BinaryTreeNode<int> *root){
    if(root==NULL){
        pair<int,int> p;
        p.first=0;
        p.second=0;
        return p;
    }
    pair<int,int> leftans=heightDiameter(root->left);
    pair<int,int> rightans=heightDiameter(root->right);
    int lh=leftans.first;
    int ld=leftans.second;
    int rh=rightans.first;
    int rd=rightans.second;

    int height=1+max(lh,rh);
    int diameter=max(lh+rh,max(ld,rd));
    pair<int,int> p;
    p.first=height;
    p.second=diameter;
    return p;
}
//1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1 
int main(){
    BinaryTreeNode<int> *root=takeInputlevelwise();
    printTree(root);
    pair<int,int> p=heightDiameter(root);
    cout<<"Height:"<<p.first<<endl;
    cout<<"Diameter:"<<p.second<<endl;
    delete root;
} 

