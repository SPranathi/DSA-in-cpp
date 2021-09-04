/*
Given a generic tree, find and return the height of given tree.
Input format :
Elements in level order form separated by space (as per done in class). Order is - 
Root_data, n (No_Of_Child_Of_Root), n children, and so on for every element 
Output Format :
Height
Sample Input :
10 3 20 30 40 2 40 50 0 0 0 0 
Sample Output :
3
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

int height(TreeNode<int> *root){
    if(root==NULL)
        return 0;
    int ans=1;
    for(int i=0;i<root->children.size();i++){
        ans=max(ans,1+height(root->children[i]));
    }
    return ans;
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
    cout<<height(root)<<endl;
}
