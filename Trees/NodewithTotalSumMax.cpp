/*
Given a tree, find and return the node for which sum of data of all children and the node itself is maximum. In the sum, data of node itself and data of immediate children is to be taken.
Input format :
Line 1 : Elements in level order form separated by space (as per done in class). Order is -
Root_data, n (No_Of_Child_Of_Root), n children, and so on for every element
Output format : Node with maximum sum.
Sample Input 1 :
5 3 1 2 3 1 15 2 4 5 1 6 0 0 0 0
Sample Output 1 :
1
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

int totalsum(TreeNode<int> *root){
    if(root==NULL)
        return 0;
    int sum=root->data;
    for(int i=0;i<root->children.size();i++){
        sum+=root->children[i]->data;
    }
    return sum;
}

TreeNode<int> *SumMax(TreeNode<int> *root){
    if(root==NULL)
        return NULL;
    if(root->children.size()==0)
        return root;
    TreeNode<int> *cur=root;
    int cur_sum=totalsum(root);
    for(int i=0;i<root->children.size();i++){
        TreeNode<int> *ans=SumMax(root->children[i]);
        int sum=totalsum(ans);
        if(cur_sum<sum){
            cur_sum=sum;
            cur=ans;
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
    TreeNode<int> *smax=SumMax(root);
    cout<<smax->data<<endl;
}


