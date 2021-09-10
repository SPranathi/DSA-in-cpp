/*
In a given Generic Tree, replace each node with its depth value. You need to just update the data of each node, no need to return or print anything.
Input format :
Line 1 : Elements in level order form separated by space (as per done in class). Order is -
Root_data, n (No_Of_Child_Of_Root), n children, and so on for every element
Sample Input 1 :
10 3 20 30 40 2 40 50 0 0 0 0 
Sample Output 1 : (Level wise, each level in new line)
0 
1 1 1 
2 2
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

void replaceWithDepth(TreeNode<int> *root,int depth){
    root->data=depth;
    for(int i=0;i<root->children.size();i++){
        replaceWithDepth(root->children[i],depth+1);
    }
}
void Depth(TreeNode<int> *root){
    if(root==NULL)
        return ;
    int depth=0;
    replaceWithDepth(root,depth);
}

void printDepth(TreeNode<int> *root){
    queue<TreeNode<int>*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        TreeNode<int> *front=q.front();
        q.pop();
        if(front==NULL){
            if(q.empty()){
                break;
            }
            cout<<endl;
            q.push(NULL);
            continue;
        }
        cout<<front->data<<" ";
        for(int i=0;i<front->children.size();i++){
            q.push(front->children[i]);
        }
    }
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
    Depth(root);
    printDepth(root);
}

