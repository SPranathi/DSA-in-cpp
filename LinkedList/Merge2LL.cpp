/*
Given two linked lists sorted in increasing order. Merge them in such a way that the result list is also sorted (in increasing order).
Try solving with O(1) auxiliary space (in-place). You just need to return the head of new linked list, don't print the elements.
Input format :
Line 1 : Linked list 1 elements of length n (separated by space and terminated by -1)
Line 2 : Linked list 2 elements of length m (separated by space and terminated by -1)
Output format :
Merged list elements (separated by space)
Constraints :
1 <= n, m <= 10^4
Sample Input :
 2 5 8 12 -1
 3 6 9 -1
Sample Output :
 2 3 5 6 8 9 12 
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
node *merge(node *head1,node *head2){
    node *head,*tail;
    if(head1->data<=head2->data){
        head=head1;
        tail=head1;
        head1=head1->next;
    }
    else{
        head=head2;
        tail=head2;
        head2=head2->next;
    }
    while(head1 && head2){
        if(head1->data<=head2->data){
            tail->next=head1;
            head1=head1->next;
            tail=tail->next;
        }
        else{
            tail->next=head2;
            head2=head2->next;
            tail=tail->next;
        }
    }
    while(head1){
        tail->next=head1;
        head1=head1->next;
        tail=tail->next;
    }
    while(head2){
        tail->next=head2;
        head2=head2->next;
        tail=tail->next;
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
    node *head1=takeinput();
    node *head2=takeinput();
    node *head=merge(head1,head2);
    print(head);
    return 0;
}   
