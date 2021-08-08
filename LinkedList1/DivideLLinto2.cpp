/*
Write a function that takes one list and divides up its nodes to create two smaller lists A and B. The sub lists should be made from alternating elements in the original list.
Nodes should be in the reverse order of which they occurred in the source list.
Print both linked lists in different lines.
Input format :
Line 1 : Linked list elements of length n (separated by space and terminated by -1)
Output format :
Line 1 : Output Linked List 1 elements (separated by space)
Line 2 : Output Linked List 2 elements (separated by space)
Constraints :
1 <= n <= 10^4
Sample Input :
 8 2 5 9 1 4 3 7 -1
Note : -1 at the end of input is just a terminator representing the end of linked list. This -1 is not part of the linked list. Size of given linked list is 8.
Sample Output :
 3 1 5 8
 7 4 9 2
*/
#include<iostream>
#include<vector>
using namespace std;
template<typename T>
class node{
public:
    T data;
    node *next;
    node(T data){
        this->data=data;
        next=NULL;
    } 
    ~node(){
        if(next!=NULL)
            delete next;
    }   
};
void  split(node<int> *head){
    if(head==NULL)
        return;
    if(head->next==NULL){
        cout<<head->data;
        return;
    }
    vector<int> v1;
    vector <int> v2;
    node<int> *ptr1=head;
    node<int> *ptr2=head->next;
    while(ptr1){
        v1.push_back(ptr1->data);
        if(ptr1->next!=NULL)
            ptr1=ptr1->next->next;
        else
        {
            break;
        }
        
    }
    while(ptr2){
        v2.push_back(ptr2->data);
        if(ptr2->next!=NULL)
            ptr2=ptr2->next->next;
        else
        {
            break;
        }
        
    }
    for(int i=v1.size()-1;i>=0;i--){
        cout<<v1[i]<<" ";
    }
    cout<<endl;
    for(int i=v2.size()-1;i>=0;i--)
        cout<<v2[i]<<" ";
        
    
}
node<int> *takeinput(){
    int data;
    cin>>data;
    node<int> *head=NULL,*tail=NULL;
    while(data!=-1){
    node<int>*newnode=new node<int>(data);
    if(head==NULL){
        head=newnode;
        tail=newnode;
        }
    else
    {
        tail->next=newnode;
        tail=newnode;
    }
    cin>>data;
    }
    return head;
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
    node<int> *head=takeinput();
    split(head);
}
  
