/*
Write a function that moves last element to front in a given singly Linked List.
For example, if the given Linked List is 1->2->3->4->5, then the function should change the list to 5->1->2->3->4.
You just need to return the head of new linked list, don't print the elements.
Input format :
Line 1 : Linked list elements of length n (separated by space and terminated by -1)
Output format :
Updated list elements (separated by space)
Constraints :
1 <= n <= 10^4
Sample Input :
 1 2 3 4 5 6 -1
Note : -1 at the end of input is just a terminator representing the end of linked list. This -1 is not part of the linked list. Size of given linked list is 6.
Sample Output :
 6 1 2 3 4 5
*/
#include<iostream>
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
node<int> *movetofront(node<int> *head){
    if(head==NULL)
        return NULL;
    if(head->next==NULL)
        return head;
    node<int> *temp=head;
    while(temp->next->next!=NULL)
        temp=temp->next;
    temp->next->next=head;
    head=temp->next;
    temp->next=NULL;
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
    head=movetofront(head);
    print(head);
    delete head;
}
 
 
