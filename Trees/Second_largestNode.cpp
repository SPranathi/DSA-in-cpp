/*
Given a generic tree, find and return the node with second largest value in given tree. Return NULL if no node with required value is present.
Input format :
Line 1 : Elements in level order form separated by space (as per done in class). Order is -
Root_data, n (No_Of_Child_Of_Root), n children, and so on for every element
Sample Input 1 :
10 3 20 30 40 2 40 50 0 0 0 0 
Sample Output 1 :
40
*/
#include<iostream>
#include<queue>
#include<vector>
using namespace std;

template<typename T>
class TreeNode{
    public:
    T data;
    vector<TreeNode<T>*> children;

    TreeNode(T data){
        this->data=data;
    }

    ~TreeNode(){
        for(int i=0;i<children.size();i++){
            delete children[i];
        }
    }
}; 

TreeNode<int> *MaxNode(TreeNode<int> *root){
    if(root==NULL)
        return NULL;
    TreeNode<int> *cur=root;
    for(int i=0;i<root->children.size();i++){
        TreeNode<int> *desc=MaxNode(root->children[i]);

        if(cur->data<desc->data){
            cur=desc;
        }
    }
    return cur;
}

TreeNode<int> *second_largestNode(TreeNode<int> *root){
    TreeNode<int> *Max=MaxNode(root);
    TreeNode<int> *cur=root;
    for(int i=0;i<root->children.size();i++){
        TreeNode<int> *desc=MaxNode(root->children[i]);

        if(desc->data!=Max->data && cur->data<desc->data){
            cur=desc;
        }
    }
    return cur;
}

TreeNode<int> *takeInputLevelWise(){
    int rootdata;
    cin>>rootdata;
    TreeNode<int> *root=new TreeNode<int>(rootdata);

    queue<TreeNode<int>*> pendingNodes;

    pendingNodes.push(root);
    while(pendingNodes.size()!=0){
        TreeNode<int> *front=pendingNodes.front();
        pendingNodes.pop();
        int numchild;
        cin>>numchild;
        for(int i=0;i<numchild;i++){
            int childData;
            cin>>childData;
            TreeNode<int> *child=new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}

int main(){
    TreeNode<int> *root=takeInputLevelWise();
    TreeNode<int> *ans=second_largestNode(root);
    if(root!=NULL){
        cout<<ans->data<<endl;
    }
}
 
