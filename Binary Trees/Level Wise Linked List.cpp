/*
Given a binary tree, write code to create a separate linked list for each level. You need to return the array which contains head of each level linked list.
Input format :
Elements in level order form (separated by space). If any node does not have left or right child, take -1 in its place.
Output format : Each level linked list is printed in new line (elements separated by space).
Sample Input :
5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1
Sample Output :
5 
6 10 
2 3 
9
=====Scratch
   5
  / \
  6 ->10
 / \  \
 2 ->3->  9
*/


#include<iostream>
#include<queue>
using namespace std;

template<typename T>
class node{
    public:
    T data;
    node<T> *next;
    node(T data){
        this->data=data;
        this->next=NULL;
    }

};

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


vector<node<int>*> createLL(BinaryTreeNode<int> *root){
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    q.push(NULL);

    vector <node<int>*> heads;
    node<int>* fhead=NULL;
    node<int>* ftail=NULL;
    while(!q.empty()){
        
        BinaryTreeNode<int>* front=q.front();
        q.pop();
        
        if(front==NULL)
            break;
        if(fhead==NULL && ftail==NULL){
            node <int>* temp=new node<int>(front->data);
            fhead=temp;
            ftail=temp;
        }
        else{
            node <int>* temp=new node<int>(front->data);
            ftail->next=temp;
            ftail=temp;
        }
        if(front->left){
            q.push(front->left);
        }
        if(front->right){
            q.push(front->right);
        }
        
        if(q.front()==NULL){
            heads.push_back(fhead);
            q.pop();
            q.push(NULL);
            fhead=NULL;
            ftail=NULL;
        }
    }
    
    return heads;

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

void print(node<int> *head){
    node<int> *temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int main(){
    BinaryTreeNode<int> *root=takeInputLevelWise();
    vector<node<int>*> ans=createLL(root);
    for(int i=0;i<ans.size();i++)
        print(ans[i]);
    delete root;
} 
