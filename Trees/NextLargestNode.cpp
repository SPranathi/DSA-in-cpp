/*
Given a generic tree and an integer n. Find and return the node with next larger element in the Tree i.e. find a node with value just greater than n.
Return NULL if no node is present with value greater than n.
Input format :
Line 1 : Integer n
Line 2 : Elements in level order form separated by space (as per done in class). Order is -
Root_data, n (No_Of_Child_Of_Root), n children, and so on for every element
Output format : Node with value just greater than n.
Sample Input 1 :
18
10 3 20 30 40 2 40 50 0 0 0 0 
Sample Output 1 :
20
Sample Input 2 :
21
10 3 20 30 40 2 40 50 0 0 0 0 
Sample Output 2:
30
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


TreeNode<int> *NextlargestNode(TreeNode<int> *root,int n){
    if(root==NULL)
        return NULL;
    TreeNode<int> *cur=NULL;
    if(root->data>n)
        cur=root;
    for(int i=0;i<root->children.size();i++){
        TreeNode<int> *desc=NextlargestNode(root->children[i],n);

        if(desc!=NULL){
            if(cur==NULL)
                cur=desc;
            if(cur->data>desc->data)
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
    int n;
    cin>>n;
    TreeNode<int> *root=takeInputLevelWise();
    TreeNode<int> *ans=NextlargestNode(root,n);
    if(root!=NULL){
        cout<<ans->data<<endl;
    }
    else{
        cout<<"NULL"<<endl;
    }
}
 
 
