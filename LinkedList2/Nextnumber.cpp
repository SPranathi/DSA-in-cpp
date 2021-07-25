/*
Given a large number represented in the form of a linked list. Write code to increment the number by 1 in-place(i.e. without using extra space).
Note: You don't need to print the elements, just update the elements and return the head of updated LL.
Input Constraints:
1 <= Length of Linked List <=10^6.
Input format :
Line 1 : Linked list elements (separated by space and terminated by -1)
Output Format :
Line 1: Updated linked list elements 
Sample Input 1 :
3 9 2 5 -1
Sample Output 1 :
3 9 2 6
Sample Input 2 :
9 9 9 -1
Sample Output 1 :
1 0 0 0 
*/
#include<iostream>
using namespace std;
class node{
public:
    int data;
    node *next;
    node(int data){
        this->data=data;
        this->next=NULL;
    } 
     
};
int fnum(node *head){
    if(head->next==NULL){
        int d=head->data+1;
        head->data=d%10;
        return d/10;
    }
    int ans=fnum(head->next);
    int d1=head->data+ans;
    head->data=d1%10;
    return d1/10;
}
node *nextnum(node *head){
    int ans=fnum(head);
    if(ans){
        node *newnode=new node(1);
        newnode->next=head;
        return newnode;
    }
    return head;
}
node *takeinput(){
    int data;
    cin>>data;
    node *head=NULL,*tail=NULL;
    while(data!=-1){
    node *newnode=new node(data);
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

void print(node *head){
    node *temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int main(){
    node *head=takeinput();
    head=nextnum(head);
    print(head);
    return 0;
}  
